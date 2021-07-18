#include <stdio.h>
#include <stdlib.h>


#include "pcm.h"
#include "pin_rate.h"
#include "pin_errs.h"
#include "pinlog.h"

int main(int argc, char **argv) {

	pin_errbuf_t	ebuf;
	//int32		flag = 33554422;
	int32		flag = 1073741825;

	PIN_ERR_CLEAR_ERR(&ebuf);

	if(argc > 1) { flag = atoi(argv[1]); }

	printf("%ld - %x\n", flag, flag);

	if(flag/PIN_RATE_FLG_CALC_MAX == 1) {
		printf("PIN_RATE_FLG_CALC_MAX\n");
		flag = flag % PIN_RATE_FLG_CALC_MAX;
	}
	if(flag/PIN_RATE_FLG_STOP_ROLLOVER == 1) {
		printf("PIN_RATE_FLG_STOP_ROLLOVER\n");
		flag = flag % PIN_RATE_FLG_STOP_ROLLOVER;
	}
	if(flag/PIN_RATE_FLG_MONITOR_ADJ_RERATE == 1) {
		printf("PIN_RATE_FLG_MONITOR_ADJ_RERATE\n");
		flag = flag % PIN_RATE_FLG_MONITOR_ADJ_RERATE;
	}
	if(flag/PIN_RATE_FLG_ALIGN == 1) {
		printf("PIN_RATE_FLG_ALIGN\n");
		flag = flag % PIN_RATE_FLG_ALIGN;
	}
	if(flag/PIN_RATE_FLG_MAINTAIN == 1) {
		printf("PIN_RATE_FLG_MAINTAIN\n");
		flag = flag % PIN_RATE_FLG_MAINTAIN;
	}
        if(flag/PIN_RATE_FLG_CUT == 1) {
                printf("PIN_RATE_FLG_CUT\n");
                flag = flag % PIN_RATE_FLG_CUT;
        }
        if(flag/PIN_RATE_FLG_CYCLE_ARREARS_REFUND == 1) {
                printf("PIN_RATE_FLG_CYCLE_ARREARS_REFUND\n");
                flag = flag % PIN_RATE_FLG_CYCLE_ARREARS_REFUND;
        }
        if(flag/PIN_RATE_FLG_RATE_CHG == 1) {
                printf("PIN_RATE_FLG_RATE_CHG\n");
                flag = flag % PIN_RATE_FLG_RATE_CHG;
        }
        if(flag/PIN_RATE_FLG_ITEM_BILLED == 1) {
                printf("PIN_RATE_FLG_ITEM_BILLED\n");
                flag = flag % PIN_RATE_FLG_ITEM_BILLED;
        }
        if(flag/PIN_RATE_FLG_PRODUCT_CANCEL == 1) {
                printf("PIN_RATE_FLG_PRODUCT_CANCEL\n");
                flag = flag % PIN_RATE_FLG_PRODUCT_CANCEL;
	}

        if(flag/PIN_RATE_FLG_CYCLE_FORWARD_ARREAR == 1) {
                printf("PIN_RATE_FLG_CYCLE_FORWARD_ARREAR\n");
                flag = flag % PIN_RATE_FLG_CYCLE_FORWARD_ARREAR;
        }
        if(flag/PIN_RATE_FLG_PRO_FORCED == 1) {
                printf("PIN_RATE_FLG_PRO_FORCED\n");
                flag = flag % PIN_RATE_FLG_PRO_FORCED;
        }
        if(flag/PIN_RATE_FLG_DISCOUNT_ONLY == 1) {
                printf("PIN_RATE_FLG_DISCOUNT_ONLY\n");
                flag = flag % PIN_RATE_FLG_DISCOUNT_ONLY;
        }
        if(flag/PIN_RATE_FLG_CYCLE_ARREARS_CHARGED == 1) {
                printf("PIN_RATE_FLG_CYCLE_ARREARS_CHARGED\n");
                flag = flag % PIN_RATE_FLG_CYCLE_ARREARS_CHARGED;
        }

        if(flag/PIN_RATE_FLG_INADVANCE_BILLING == 1) {
                printf("PIN_RATE_FLG_INADVANCE_BILLING\n");
                flag = flag % PIN_RATE_FLG_INADVANCE_BILLING;
        }
        if(flag/PIN_RATE_FLG_RERATE == 1) {
                printf("PIN_RATE_FLG_RERATE\n");
                flag = flag % PIN_RATE_FLG_RERATE;
        }
        if(flag/PIN_RATE_FLG_RATE_ONLY == 1) {
                printf("PIN_RATE_FLG_RATE_ONLY\n");
                flag = flag % PIN_RATE_FLG_RATE_ONLY;
        }
        if(flag/PIN_RATE_FLG_REACTIVATE == 1) {
                printf("PIN_RATE_FLG_REACTIVATE\n");
                flag = flag % PIN_RATE_FLG_REACTIVATE;
        }

        if(flag/PIN_RATE_FLG_CYCLE_CHARGED == 1) {
                printf("PIN_RATE_FLG_CYCLE_CHARGED\n");
                flag = flag % PIN_RATE_FLG_CYCLE_CHARGED;
        }
        if(flag/PIN_RATE_FLG_DEFERRED == 1) {
                printf("PIN_RATE_FLG_DEFERRED\n");
                flag = flag % PIN_RATE_FLG_DEFERRED;
        }
        if(flag/PIN_RATE_FLG_FAIL_ON_CREDIT_LIMIT == 1) {
                printf("PIN_RATE_FLG_FAIL_ON_CREDIT_LIMIT\n");
                flag = flag % PIN_RATE_FLG_FAIL_ON_CREDIT_LIMIT;
        }
        if(flag/PIN_RATE_FLG_PRO_NORMAL == 1) {
                printf("PIN_RATE_FLG_PRO_NORMAL\n");
                flag = flag % PIN_RATE_FLG_PRO_NORMAL;
        }

        if(flag/PIN_RATE_FLG_DEFERRED_CYCLE_AT_MIDNIGHT == 1) {
                printf("PIN_RATE_FLG_DEFERRED_CYCLE_AT_MIDNIGHT\n");
                flag = flag % PIN_RATE_FLG_DEFERRED_CYCLE_AT_MIDNIGHT;
        }
        if(flag/PIN_RATE_FLG_PRO_LAST == 1) {
                printf("PIN_RATE_FLG_PRO_LAST\n");
                flag = flag % PIN_RATE_FLG_PRO_LAST;
        }
        if(flag/PIN_RATE_FLG_PRO_FIRST == 1) {
                printf("PIN_RATE_FLG_PRO_FIRST\n");
                flag = flag % PIN_RATE_FLG_PRO_FIRST;
        }
        if(flag/PIN_RATE_FLG_INVERTED == 1) {
                printf("PIN_RATE_FLG_INVERTED\n");
                flag = flag % PIN_RATE_FLG_INVERTED;
        }
        if(flag/PIN_RATE_FLG_OVERRIDE_CREDIT_LIMIT == 1) {
                printf("PIN_RATE_FLG_OVERRIDE_CREDIT_LIMIT\n");
                flag = flag % PIN_RATE_FLG_OVERRIDE_CREDIT_LIMIT;
        }
	return 0;
}
