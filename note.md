#### 回调

    在C和C++中，回调是模块A中的一个函数指针，该指针被传递给模块B，这样B就能在合适的时间调用A中的函数。模块B对模块A一无所知，并且对模块A不存在“包含”（include）或者“链接”（link）依赖。回调的这种特性使得低层代码能够执行与其不能有依赖关系的高层代码。因此，在大型项目中，回调是一种打破循环依赖的常用技术。
    例子：拾取时射线与场景求交的交点问题。首先底层这边通过射线与场景求交，如果当前射线与场景中的图元没有交点，则通过回调来询问上层是否能给出交点（一般上层会给出射线与工作平面的交点），如果上层也不知道给出哪个交点，则底层采用给出默认交点（当前场景包围盒的中心点）。
    
        typedef std::function<bool (void* pContext, CVector3f& pt)> PivotPointCallbackFun; // 回调声明
        void SetPivotPointCallbackFun(const PivotPointCallbackFun& callback, void* pContext); // 注册回调
 
        if (!GetHitObjectPt(pArgs->X(), pArgs->Y(), pt, pPalceAnchorSphereNodeFilter))
        {
            if (nullptr != m_pivotPointCallbackFun)
            {
                if (!m_pivotPointCallbackFun(m_pContext, pt)) // 底层执行高层代码
                {
                    pt = this->Scene()->GetClippedSafeBoundingBox().CenterPt();
                }
            }
        }
    
    上层回调具体实现
    
        SetPivotPointCallbackFun([](void* pContext, CVector3f& pt) -> bool
        {
            if (!pContext)
            {
                return false;
            }
            IGMPService* pService = (IGMPService*)pContext;
            CCoordinates3d oCoord;
            if (IGMPWorkPlane* pWorkPlane = pService->state()->curWorkPlane())
            {
                oCoord = pWorkPlane->coordinate();
            }
            else
            {
                double dZ = pService->state()->curFloor()->btmElev() * 1000;
                oCoord.Origin.Z = dZ;
            }
            CVector3d oPos = pService->modelViewer()->RealViewer()->GetCamera()->Position().Vec3d().LocalPoint(oCoord);
            CVector3d oDir = pService->modelViewer()->RealViewer()->GetCamera()->Direction().Vec3d().LocalVector(oCoord);
            if (ggp::isZero(oDir.Z, g_DistEpsilon))
            {
                return false;
            }
            pt = (oPos - oDir / oDir.Z * oPos.Z).WorldPoint(oCoord).Vec3f();
            return true;
        }, m_piService);

#### 观察者模式

    观察者模式是“发布/订阅”范式的一个具体实例。这些技术定义了对象之间一对多的依赖，使得发布者对象能够将它的状态变化通知给所有的订阅对象，而又不直接依赖于订阅者对象。在API设计邻域，观察者模式是一个重要的技巧，因为它能帮助降低耦合度并提高代码复用性。
