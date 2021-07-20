#include <stdio.h>
#include <stdlib.h>


#include "pcm.h"
#include "pin_errs.h"
#include "pinlog.h"

void display_usage() {
	printf("\nUsage : flist_soft <main_flist> <sort_flist>\n\n");
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
	pin_flist_t		*c_flistp = NULL;
	pin_flist_t		*sort_flistp = NULL;
	pin_errbuf_t	ebuf;
	char	*i_buffer = NULL;
	char	*s_buffer = NULL;

	PIN_ERR_CLEAR_ERR(&ebuf);

	//Validate the usage
	if(argc < 3) {
		printf("\nIncorrect Usage\n");
		display_usage();
		exit(1);
	}

	//Convert file as string
	read_file_as_string(argv[1], &i_buffer);
	read_file_as_string(argv[2], &s_buffer);

	//convert string into flist
	PIN_STR_TO_FLIST(i_buffer, 1, &i_flistp, &ebuf);
	PIN_STR_TO_FLIST(s_buffer, 1, &sort_flistp, &ebuf);

	//Soriting the flist
	c_flistp = PIN_FLIST_COPY(i_flistp, &ebuf);

	if(argv[3] && strcmp(argv[3], "-reverse") == 0) {
		PIN_FLIST_SORT_REVERSE(c_flistp, sort_flistp, 0, &ebuf);
	}
	else {
		PIN_FLIST_SORT(c_flistp, sort_flistp, 0, &ebuf);
	}

	PIN_FLIST_PRINT(c_flistp, NULL, &ebuf);
	return 0;
}

/*Sample Flists

--input
0 PIN_FLD_DEALS         ARRAY [0] allocated 20, used 4
1     PIN_FLD_PACKAGE_ID      INT [0] 113026859
1     PIN_FLD_DEAL_OBJ       POID [0] 0.0.0.1 /deal 51774491390 0
1     PIN_FLD_SERVICE_OBJ    POID [0] 0.0.0.1 /service/intuit/qbo 8909919 0
1     PIN_FLD_TYPE_OF_SERVICE    INT [0] 1
0 PIN_FLD_DEALS         ARRAY [1] allocated 20, used 4
1     PIN_FLD_PACKAGE_ID      INT [0] 113026860
1     PIN_FLD_DEAL_OBJ       POID [0] 0.0.0.1 /deal 158219731668 0
1     PIN_FLD_SERVICE_OBJ    POID [0] 0.0.0.1 /service/intuit/qbo/qbop 8909919 7
1     PIN_FLD_TYPE_OF_SERVICE    INT [0] 0
0 PIN_FLD_DEALS         ARRAY [2] allocated 20, used 4
1     PIN_FLD_PACKAGE_ID      INT [0] 113026861
1     PIN_FLD_DEAL_OBJ       POID [0] 0.0.0.1 /deal 157598822231 0
1     PIN_FLD_SERVICE_OBJ    POID [0] 0.0.0.1 /service/intuit/qbot 8923559 0
1     PIN_FLD_TYPE_OF_SERVICE    INT [0] 0
0 PIN_FLD_DEALS         ARRAY [3] allocated 20, used 4
1     PIN_FLD_PACKAGE_ID      INT [0] 113026862
1     PIN_FLD_DEAL_OBJ       POID [0] 0.0.0.1 /deal 157598822231 0
1     PIN_FLD_SERVICE_OBJ    POID [0] 0.0.0.1 /service/intuit/qbo 8923559 0
1     PIN_FLD_TYPE_OF_SERVICE    INT [0] 1
1     PIN_FLD_NAME   STR [0] "discount"
0 PIN_FLD_DEALS         ARRAY [4] allocated 20, used 4
1     PIN_FLD_PACKAGE_ID      INT [0] 113026863
1     PIN_FLD_DEAL_OBJ       POID [0] 0.0.0.1 /deal 157598822231 0
1     PIN_FLD_SERVICE_OBJ    POID [0] 0.0.0.1 /service/intuit/qbot 8923559 0
1     PIN_FLD_TYPE_OF_SERVICE    INT [0] 0
1     PIN_FLD_NAME   STR [0] "discount"

--sort_flist
0 PIN_FLD_DEALS         ARRAY [*] allocated 20, used 5
1     PIN_FLD_TYPE_OF_SERVICE    INT [0] 0

*/
