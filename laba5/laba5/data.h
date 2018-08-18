typedef struct serial
{
	int kolvo;
	char *nazv;
	struct dop
	{
		char data[10];
		int sezon;
	}dop;
}serial;

int setInfo(struct serial *);
void showInfo(struct serial *);