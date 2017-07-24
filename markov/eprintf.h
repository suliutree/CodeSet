extern void eprintf(char *, ...);
extern void weprintf(char *, ...);
extern char *estrdup(char *);
extern void *emalloc(size_t);
extern char *progname(void);
extern void setprogname1(char *);

#define NELEMS(a)	(sizeof(a) / sizeof(a[0]))
