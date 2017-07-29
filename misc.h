/*
vim: cindent
vim: background=dark
vim: tabstop=2 shiftwidth=2 expandtab
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <zlib.h>
#include <unistd.h>

struct MemoryStruct {
  char *memory;
  size_t size;
};

struct rpm  {
  char *name, *arch, *version, *release, *checksum_type, *checksum, *location;
  size_t size;
  bool action;
};

int get_http_to_file(FILE *fp,char *url, bool verbose);

int uncompress_file(char *filename, Byte **content);

void print_element_names(xmlNode * a_node);

xmlXPathObjectPtr getnodeset(xmlDocPtr doc, xmlChar *namespace, xmlChar *xpath);

int get_primary_url(char *repomd_xml, char **postfix);

int get_xml(char *url, char **xml);

int get_primary_xml(char *repo, char **primary_xml);

void print_rpms(struct rpm *rpms, int size);

int ensure_dir(char *basedir, char *location, bool noop);

int check_rpm_exists(char *targetdir, struct rpm rpm);

int xferinfo(void *p, curl_off_t dltotal, curl_off_t dlnow, curl_off_t utotal, curl_off_t ulnow);

void usage(void);