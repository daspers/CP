var
	N,yl: integer;
	D : boolean;
	x,y : String;

begin
	readln(x);
	N:=pos(' ',x);
	y :=copy(x,N+1,length(x)-N);
	delete(x,N,length(x)-N+1);
	yl:=length(y);
	D:=true;
	while (D) and (length(x)>0) do begin
		D:=false;
		N:= pos(y,x);
		if(N>0) then begin
			delete(x,N,yl);
			D:=true;
		end;
	end;
	writeln(x);
end.
