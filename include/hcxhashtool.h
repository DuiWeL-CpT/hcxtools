#define HCX_TYPE_PMKID		1
#define HCX_TYPE_EAPOL		2

#define ESSID_LEN_MAX 		32
#define EAPOL_AUTHLEN_MAX	256

#define PMKIDEAPOL_LINE_LEN	1024
#define PMKIDEAPOL_BUFFER_LEN	1024
#define HASHLIST_MAX		10


#define HCX_PMKIDEAPOL_IN	'i'
#define HCX_ESSID_OUT		'E'

#define HCX_HELP		'h'
#define HCX_VERSION		'v'
/*===========================================================================*/
/*===========================================================================*/
struct hashlist_s
{
 uint8_t		type;
#define HS_PMKID	1;
#define HS_EAPOL	2;
 uint8_t		hash[16];
 uint8_t		ap[6];
 uint8_t		client[6];
 uint8_t		essidlen;
 uint8_t		essid[ESSID_LEN_MAX];
 uint8_t		nonce[32];
 uint16_t		eapauthlen;
 uint8_t		eapol[EAPOL_AUTHLEN_MAX];
 uint8_t		mp;
};
typedef struct hashlist_s hashlist_t;
#define	HASHLIST_SIZE (sizeof(hashlist_t))

static int sort_maclist_by_essid(const void *a, const void *b)
{
const hashlist_t *ia = (const hashlist_t *)a;
const hashlist_t *ib = (const hashlist_t *)b;
if(memcmp(ia->essid, ib->essid, ESSID_LEN_MAX) > 0) return 1;
else if(memcmp(ia->essid, ib->essid, ESSID_LEN_MAX) < 0) return -1;
return 0;
}

/*===========================================================================*/




