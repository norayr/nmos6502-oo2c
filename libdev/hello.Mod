MODULE hello;
IMPORT Out,In;
VAR ch : CHAR;
str : ARRAY 7 OF CHAR;
BEGIN
Out.String ("Hello World for Oric Atmos in Oberon");
Out.Ln; Out.Ln; Out.Ln; Out.Ln;
(*
In.Char(ch); Out.Ln;
Out.Char(ch);
Out.Ln
*)
In.String(str);
Out.Ln;
Out.Ln;
Out.Ln;
Out.String("you entered: ");
Out.String(str);
Out.Ln;
Out.Ln;
Out.Ln
END hello.

