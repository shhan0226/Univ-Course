#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replaceAll(char *s, const char *olds, const char *news);


int main(){
  char s[] = "봉숭아 학당! 봉숭아 학당! 봉숭아 학당! 봉숭아 학당!";
  char *s2;

  printf("원본: %s\n", s);

  s2 = replaceAll(s, "봉숭아", "맹구");

  // 에러가 있으면 NULL 을 리턴. 에러가 없으면 결과 출력
  (s2 != NULL) ? printf("치환: %s\n", s2) : fputs("Replace String Error...\n", stderr);
}




char *replaceAll(char *s, const char *olds, const char *news) {
  char *result, *sr;
  size_t i, count = 0;
  size_t oldlen = strlen(olds); if (oldlen < 1) return s;
  size_t newlen = strlen(news);


  if (newlen != oldlen) {
    for (i = 0; s[i] != '\0';) {
      if (memcmp(&s[i], olds, oldlen) == 0) count++, i += oldlen;
      else i++;
    }
  } else i = strlen(s);


  result = (char *) malloc(i + 1 + count * (newlen - oldlen));
  if (result == NULL) return NULL;


  sr = result;
  while (*s) {
    if (memcmp(s, olds, oldlen) == 0) {
      memcpy(sr, news, newlen);
      sr += newlen;
      s  += oldlen;
    } else *sr++ = *s++;
  }
  *sr = '\0';

  return result;
}
