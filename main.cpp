#include "module.h"

using namespace std;

void create_new_disk(list* &disks)
{
	list *current = disks;
	list *newdisk = new list;
	newdisk->next = NULL;
	if (disks)
	{
		while (current->next)
			current = current->next;
		current->next = newdisk;
	}
	else
		disks = newdisk;
}

void freemem(list *disks)
{
	if (disks)
	{
		freemem(disks->next);
		delete disks;
	}
}

int main()
{
	Centr c;
	int get = 0;
	list *disks = NULL;
	while (get != 7)
	{
		cout << "enter option\n[1]> Get info about centr\n[2]> Create new disk\n[3]> Lower the volume\n[4]> Increase the volume\n[5]> eject or insert disk\n[6]> Next song\n[7]> End work\n";
		cin >> get;
		switch (get)
		{
			case 1:
			{
				c.getinfo();
				break;
			}
			case 2:
			{
				create_new_disk(disks);
				break;
			}
			case 3:
			{
				c.change_vol(0);
				break;
			}
			case 4:
			{
				c.change_vol(1);
				break;
			}
			case 5:
			{
				c.eject_or_insert(disks);
				break;
			}
			case 6:
			{
				c.get_next_song();
				break;
			}
			case 7:
			{
				break;
			}
			default:
			{
				cout << "Bad choise" << endl;
				break;
			}
		}
	}
	freemem(disks);
	return 1;
}
