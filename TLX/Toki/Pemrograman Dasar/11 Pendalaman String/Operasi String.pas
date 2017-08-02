var
	N: integer;
	a,b,c,d : String;

begin
	readln(a);
	readln(b);
	readln(c);
	readln(d);
	N:=pos(b,a);
	delete(a,N,length(b));
	N:=pos(c,a);
	insert(d,a,N+length(c));
	writeln(a);
end.
