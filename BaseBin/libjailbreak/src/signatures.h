#ifndef SIGNATURES_H
#define SIGNATURES_H

#include <choma/CodeDirectory.h>

typedef enum {
	SIGNATURE_SOURCE_FILE,
	SIGNATURE_SOURCE_PROC,
} signature_source_t;

struct siginfo {
	signature_source_t source;
	fsignatures_t signature;
};

typedef uint8_t cdhash_t[CS_CDHASH_LEN];

void macho_collect_untrusted_cdhashes(const char *path, const char *callerImagePath, const char *callerExecutablePath, uint32_t *preferredArchTypes, uint32_t *preferredArchSubtypes, size_t preferredArchCount, cdhash_t **cdhashesOut, uint32_t *cdhashCountOut);

#endif