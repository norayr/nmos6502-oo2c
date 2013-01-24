MODULE Out [OOC_EXTENSIONS];

IMPORT Terminal;

CONST
  CR * = 0DX;
  LF * = 0AX;

PROCEDURE Char* (c : CHAR);
BEGIN
  Terminal.Put(c);
END Char;

PROCEDURE String* (s [NO_COPY] : ARRAY OF CHAR);
VAR ch : CHAR; i : INTEGER;
BEGIN
  i := 0;
  LOOP
    ch := s[i];
    IF ch = 0X THEN EXIT END;
    Terminal.Put(ch);
    INC(i);
  END;
END String;
PROCEDURE Int* (i, n : LONGINT);
BEGIN
FOR i := 0 TO n DO
Terminal.Put(" ")
END;
Terminal.PutInt (i);
END Int;

PROCEDURE Ln*;
BEGIN
Terminal.Put(CR);
(*Terminal.Put(LF);*)
END Ln;
PROCEDURE Open*;
BEGIN
END Open;


END Out.
