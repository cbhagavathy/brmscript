#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#include "pcm.h"
#include "pin_errs.h"
#include "pinlog.h"

#include "./ops/base.h"

void display_usage() {
	printf("\nUsage : get_dscmdl <discount_model>\n\n");
}


void read_file_as_string(char *fname, char **i_buffer) {
	FILE *fp = fopen(fname, "rb");
	long length;

	if(fp != NULL) {
		fseek(fp, 0, SEEK_END);
		length = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		*i_buffer = malloc(length);
		fread(*i_buffer, 1, length, fp);
	}
	fclose(fp);
}


int main(int argc, char **argv) {

	pin_flist_t		*i_flistp = NULL;
	pin_flist_t		*args_flistp = NULL;
	pin_flist_t		*r_flistp = NULL;
	pin_flist_t		*d_flistp = NULL;
	pin_errbuf_t		ebuf;
	char			*i_buffer = NULL;
	int64			database;
	pcm_context_t           *ctxp;
	pin_buf_t   		*bufp      = NULL;
	char        		*bufferp       = NULL;

	PIN_ERR_CLEAR_ERR(&ebuf);

	//Validate the usage
	if(argc != 2) {
		printf("\nIncorrect Usage\n");
		display_usage();
		exit(1);
	}

	//Convert file as string
	read_file_as_string("search_dscmdl.input", &i_buffer);

	//convert string into flist
	PIN_STR_TO_FLIST(i_buffer, 1, &i_flistp, &ebuf);

	//Set the code
	args_flistp = PIN_FLIST_ELEM_GET(i_flistp, PIN_FLD_ARGS, 1, 0, &ebuf);
	PIN_FLIST_FLD_SET(args_flistp, PIN_FLD_DISCOUNT_MODEL, argv[1], &ebuf);

	//PIN_FLIST_PRINT(i_flistp, NULL, &ebuf);

	//Open the connection
	PCM_CONNECT(&ctxp, &database, &ebuf);

	//Call PCM_OP_EXEC_SPROC
	PCM_OP(ctxp, PCM_OP_EXEC_SPROC, 0, i_flistp, &r_flistp, &ebuf);

	//Read buffer and convert it into FLIST
	args_flistp = PIN_FLIST_ELEM_GET(r_flistp, PIN_FLD_ARGS, 2, 1, &ebuf );
	bufp = PIN_FLIST_FLD_GET( args_flistp, PIN_FLD_BUFFER, 1, &ebuf );
	bufferp = (char*) pin_malloc( bufp->size + 1 );
	strncpy( bufferp, bufp->data, bufp->size );
	bufferp[bufp->size] = '\0';

	printf("\n%s\n\n", bufferp);

	//Close the connection
	PCM_CONTEXT_CLOSE(ctxp, 0, &ebuf);

	return 0;
}
