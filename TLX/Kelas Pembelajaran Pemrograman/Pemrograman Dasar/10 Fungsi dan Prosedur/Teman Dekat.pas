type
	point = record
		x,
		y : integer;
	end;

var
	N,D,i,k,m,min,maks : integer;
	P : array of point;
	T : array of longint;
	
function powers(a,b :integer) : longint;
 var
	j:integer;
	H :longint;
begin
	H:=1;
	for j:=1 to b do
		H:=H*a;
	powers:=H;
end;
	
begin
	read(N,D);
	setlength(P,N);
	setlength(T,(N-1)*N div 2);
	for i:=0 to N-1 do begin
		readln(P[i].x,P[i].y);
	end;
	m:=0;
	min:=0;
	maks:=0;
	for i:=0 to N-1 do begin
		for k:=i+1 to N-1 do begin
			T[m] := powers(abs(P[i].x-P[k].x),D) + powers(abs(P[i].y-P[k].y),D);
			m:=m+1;
		end;
	end;
	for i:=1 to m-1 do begin
		if(T[i]<T[min]) then min:=i;
		if(T[i]>T[maks]) then maks:=i;
	end;
	writeln(T[min],' ',T[maks]);
end.
