var
	N,i: integer;
	D : char;
	x : String;

begin
	readln(x,N);
	for i:=1 to length(x) do begin
		D:=chr((ord(x[i])+N-ord('a'))mod 26 +ord('a'));
		x[i]:=D;
	end;
	writeln(x);
end.
