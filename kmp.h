#ifndef __KMP_H__
#define __KMP_H__
 
#ifdef __cplusplus
extern "C" {
#endif
 
extern int nkmp(const char src[], const char key[], int len_of_src, int len_of_key);
extern int kmp(const char *src, const char *key);
 
#ifdef __cplusplus
}
#endif
 
#endif // __KMP_H__