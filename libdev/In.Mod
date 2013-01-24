MODULE In[OOC_EXTENSIONS];
IMPORT Terminal;

PROCEDURE Char* (VAR ch : CHAR);
VAR a : CHAR;
BEGIN
Terminal.Get(a);
ch := a;
REPEAT
Terminal.Get(a)
UNTIL a = 0DX
END Char;
PROCEDURE String* ( VAR s : ARRAY OF CHAR);
VAR n : CHAR;
l : LONGINT;
BEGIN
l := 0;
REPEAT
Terminal.Get(n);
   IF (n >= 20X) THEN
   s[l] := n;
   Terminal.Put(n);
   INC(l)
   END;
UNTIL ((n < 20X) OR (l = LEN(s)-1));
s[l] := 0X
END String;
PROCEDURE Open*;
BEGIN
END Open;
PROCEDURE Int* (VAR i : INTEGER);
BEGIN
END Int;

END In.
