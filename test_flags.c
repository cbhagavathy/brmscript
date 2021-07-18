#include <stdio.h>
#include <stdlib.h>


#include "pcm.h"
#include "pin_rate.h"
#include "pin_errs.h"
#include "pinlog.h"

int main(int argc, char **argv) {

	pin_errbuf_t	ebuf;
	int32		flag = 33554422;
	int32		new_flag;

        int32   flags = PIN_RATE_FLG_INVERTED|PIN_RATE_FLG_PRO_LAST|PIN_RATE_FLG_CUT|PIN_RATE_FLG_STOP_ROLLOVER;
        int32   nflags = PIN_RATE_FLG_INVERTED|PIN_RATE_FLG_PRO_FIRST|PIN_RATE_FLG_PRO_NORMAL|PIN_RATE_FLG_PRO_FORCED|PIN_RATE_FLG_CUT|PIN_RATE_FLG_STOP_ROLLOVER;

	int32	ovd_flags, exc_flags;

	PIN_ERR_CLEAR_ERR(&ebuf);

	printf("\nTesting BRM Flags\n");

	printf("Flag : %ld\n", flag);

	new_flag = (flag & !PIN_RATE_FLG_PRO_LAST) | PIN_RATE_FLG_PRO_NORMAL;
	printf("Apply - new_flag = (flag & !PIN_RATE_FLG_PRO_LAST) | PIN_RATE_FLG_PRO_NORMAL\n");

	printf("New Flag : %ld\n", new_flag);

	printf("\nFlags : %ld\n", flags);
	printf("\nnFlags : %ld\n", nflags);

	ovd_flags = PIN_RATE_FLG_PRO_NORMAL|PIN_RATE_FLG_PRO_FORCED;
	printf("\novd_flags : %ld\n", ovd_flags);
	ovd_flags = PIN_RATE_FLG_PRO_NORMAL|PIN_RATE_FLG_PRO_FORCED;
	printf("\novd_flags : %ld\n", ovd_flags);
	ovd_flags = PIN_RATE_FLG_PRO_FORCED;
	printf("\novd_flags : %ld\n", ovd_flags);
	exc_flags = (PIN_RATE_FLG_PRO_LAST|PIN_RATE_FLG_PRO_FIRST);
	printf("\nexc_flags : %ld\n", exc_flags);


	return 0;
}
