#!/bin/sh

#Script to delete all the account except the ROOT

#Getting all the accounts
testnap << XXX > all_accts.out
r << xx 1
0 PIN_FLD_POID           POID [0] 0.0.0.1 /search -1 0
0 PIN_FLD_FLAGS           INT [0] 256
0 PIN_FLD_TEMPLATE        STR [0] "select X from /account where F1 != V1 "
0 PIN_FLD_ARGS          ARRAY [1] allocated 20, used 1
1     PIN_FLD_ACCOUNT_NO           STR [0] "ROOT"
0 PIN_FLD_RESULTS       ARRAY [0]
1     PIN_FLD_POID           POID [0] NULL
xx
xop 7 0 1
XXX
cat all_accts.out | grep account > all_accts_poids.out

#looping through the results and calling CUST_DELETE_ACCT
sed -i 's/^1/0/g' all_accts_poids.out

while read line; do
        testnap << xx
r << X 1
$line
X
xop PCM_OP_CUST_DELETE_ACCT 0 1
xx
done < all_accts_poids.out

rm all_accts_poids.out all_accts.out
