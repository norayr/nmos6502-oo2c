MODULE Terminal [FOREIGN "C"; LINK FILE "Terminal.c" END];
PROCEDURE Put* (c: CHAR);
PROCEDURE PutInt* (c : LONGINT);
PROCEDURE Get* (VAR c : CHAR);
END Terminal.
