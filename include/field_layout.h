int FIELD_WIDTH = 0;
int FIELD_LENGTH =  0;
int FIELD_HEIGHT = 0;

struct Coord{
	int x, y, z;
	Coord(int x, int y, int z) : x(x), y(y), z(z){}
};

Coord FIELD_BALLS[] = {
	Coord(0,0,0),
	Coord(0,1,0),
	Coord(1,1,0),
};

Coord FIELD_PEGS[] = {
	Coord(0,0,0),
	Coord(0,1,0),
	Coord(1,1,0),
};

Coord FIELD_DISKS[] = {
	Coord(0,0,0),
	Coord(0,1,0),
	Coord(1,1,0),
};

Coord FIELD_FLAGS[] = {
	Coord(0,0,0),
	Coord(0,1,0),
	Coord(1,1,0),
};
