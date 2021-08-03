
CREATE OR REPLACE PROCEDURE get_account_dtls ( 
    acc_db IN NUMBER , acc_type IN VARCHAR2, acc_poid IN NUMBER, acc_rev IN NUMBER, 
    v_account_no OUT account_t.ACCOUNT_NO%type,
    v_currency OUT account_t.CURRENCY%type) AS 
BEGIN
    SELECT account_no, currency INTO v_account_no, v_currency
    FROM account_t 
    WHERE poid_id0 = acc_poid;
END;
/
