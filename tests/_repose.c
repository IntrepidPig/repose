#define SIZE_MAX ...

typedef int... time_t;

typedef struct __alpm_list_t {
    void *data;
    struct __alpm_list_t *next;
    ...;
} alpm_list_t;

struct pkg {
    char *filename;
    char *name;
    char *base;
    char *version;
    char *desc;
    char *url;
    char *packager;
    char *sha256sum;
    char *base64sig;
    char *arch;
    size_t size;
    size_t isize;
    time_t builddate;
    time_t mtime;

    alpm_list_t *groups;
    alpm_list_t *licenses;
    alpm_list_t *replaces;
    alpm_list_t *depends;
    alpm_list_t *conflicts;
    alpm_list_t *provides;
    alpm_list_t *optdepends;
    alpm_list_t *makedepends;
    alpm_list_t *checkdepends;
    alpm_list_t *files;
    ...;
};

enum pkg_entry {
    PKG_FILENAME,
    PKG_PKGNAME,
    PKG_PKGBASE,
    PKG_VERSION,
    PKG_DESCRIPTION,
    PKG_GROUPS,
    PKG_CSIZE,
    PKG_ISIZE,
    PKG_SHA256SUM,
    PKG_PGPSIG,
    PKG_URL,
    PKG_LICENSE,
    PKG_ARCH,
    PKG_BUILDDATE,
    PKG_PACKAGER,
    PKG_REPLACES,
    PKG_DEPENDS,
    PKG_CONFLICTS,
    PKG_PROVIDES,
    PKG_OPTDEPENDS,
    PKG_MAKEDEPENDS,
    PKG_CHECKDEPENDS,
    PKG_FILES,
    PKG_BACKUP,
    PKG_DELTAS,
    PKG_MAKEPKGOPT,
    PKG_XDATA
};

// desc
struct desc_parser {
    enum pkg_entry entry;
    ...;
};

void desc_parser_init(struct desc_parser *parser);
ssize_t desc_parser_feed(struct desc_parser *parser, struct pkg *pkg,
                         char *buf, size_t buf_len);

// pkginfo
struct pkginfo_parser {
    enum pkg_entry entry;
    ...;
};

void pkginfo_parser_init(struct pkginfo_parser *parser);
ssize_t pkginfo_parser_feed(struct pkginfo_parser *parser, struct pkg *pkg,
                            char *buf, size_t buf_len);

// utils
char *joinstring(const char *root, ...);
int parse_size(const char *str, size_t *out);
int parse_time(const char *size, time_t *out);
char *strstrip(char *s);
