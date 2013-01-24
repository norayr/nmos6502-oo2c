MODULE ooptest; 
IMPORT 
 Out; 


TYPE  T = RECORD x, y:  SHORTINT  END; 
TYPE 
   T0 = RECORD (T) z: SHORTINT END;  (* extension of T *) 
   T1 = RECORD (T) w: SHORTINT END; (* extension of T *) 
TYPE 
    action  = PROCEDURE (a,b: SHORTINT): SHORTINT; (* a procedural type 
*) 
    T2 = RECORD (T) 
          Add: action   (*  "Add" is a "method" of the T2 class *) 
        END; 


VAR 
  object: T2; result: SHORTINT; 


PROCEDURE AddIt(a, b : SHORTINT): SHORTINT; 
BEGIN 
        RETURN a + b; 
END AddIt; 


PROCEDURE Do*; 
BEGIN 
        Out.Int(result,0); 
        Out.Ln; 
END Do; 


BEGIN 
  object.x := 123; object.y := 4; object.Add := AddIt; 
  result := object.Add (object.x, object.y); (* method call *) 
  Do
END ooptest.

