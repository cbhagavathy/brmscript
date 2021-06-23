#include <stdio.h>
#include <stdlib.h>


#include "pcm.h"
#include "pin_errs.h"
#include "pinlog.h"


typedef struct {
    int32 chunksize;
    char *strp;
    int32 size;
    int32 strsize;
} buf_t;

void display_usage() {
	printf("\nUsage : flist2xml <filename>\n\n");
}

void read_file_as_string(char *fname, char **buffer) {
	FILE *fp = fopen(fname, "rb");
	long length;

	if(fp != NULL) {
		fseek(fp, 0, SEEK_END);
		length = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		*buffer = malloc(length);
		fread(*buffer, 1, length, fp);
	}
	fclose(fp);
}
	

int main(int argc, char **argv) {

	buf_t    dbuf;
	pin_flist_t		*i_flistp = NULL;
	pin_errbuf_t	ebuf;
	char	*buffer = NULL;


	PIN_ERR_CLEAR_ERR(&ebuf);

	//Validate the usage 
	if(argc != 2) {
		printf("\nIncorrect Usage\n");
		display_usage();
		exit(1);
	}

	//Convert file as string
	read_file_as_string(argv[1], &buffer);

	//convert string into flist
	PIN_STR_TO_FLIST(buffer, 1, &i_flistp, &ebuf);

	//Convert flist into XML 
	dbuf.strp = NULL;
	dbuf.strsize = 0;
	PIN_FLIST_TO_XML( i_flistp, PIN_XML_BY_SHORT_NAME, 0, &dbuf.strp, &dbuf.strsize, "flist", &ebuf );
	dbuf.strsize -= 2;
	printf("%s", dbuf.strp);

	return 0;
}

