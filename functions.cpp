#include "module.h"
#include <cstdio>

using namespace std;

Button::Button()
{
}

disk::disk()
{
	cursong = 0;
	cout << "enter name of disk" << endl;
	cin >> name;
	cout << "enter number of songs" << endl;
	cin >> size;
	songs = new string[size];
	for (int i = 0; i < size; i++)
	{
		cout << "enter name of " << i + 1 << " song" << endl;
		cin >> songs[i];
	}
}

string disk::getname()
{
	return name;
}

void Centr::getinfo()
{
	cout << "volume is " << volume << endl;
	if (tray.getdisk())
	{
		cout << tray.get_cur_song() << " is now playing" << endl;
		cout << tray.get_cur_name() << " is in tray now" << endl;
	}
	else
	{
		cout << "nothing playing" << endl;
		cout << "disk tray is empty" << endl;
	}
}

Button_eject_insert::Button_eject_insert()
{
	cout << "enter color for button_eject_insert" << endl;
	cin >> color;
	state = "open";
}

Button_change_volume_up::Button_change_volume_up()
{
	cout << "enter color for button_change_volume up" << endl;
	cin >> color;
}

Button_change_volume_down::Button_change_volume_down()
{
	cout << "enter color for button_change_volume down" << endl;
	cin >> color;
}

Button_next_song::Button_next_song()
{
	cout << "enter color for Button_next_song" << endl;
	cin >> color;
}

void Button_change_volume_down::press(int &volume)
{
	cout << "you pressed " << color << " button" << endl;
	if (volume != 0)
		volume--;
}

void Button_change_volume_up::press(int &volume)
{
	cout << "you pressed " << color << " button" << endl;
	if (volume != 20)
		volume++;
}

Centr::Centr()
{
	volume = 10;
	tray.set_cur_disk(NULL);
}

void disk::getnextsong()
{
	cursong++;
	cout << "cursong " << cursong << " size" << size << endl;
	if (cursong == size)
		cursong = 0;
}

void Button_eject_insert::press(list* &disks, disk_tray &tray)
{
	cout << "you pressed " << color << " button" << endl;
	if (tray.getdisk() == NULL)
	{
		if (!disks)
		{
			cout << "Error! No disks!" << endl;
			return ;
		}
		list *current = disks;
		while (current)
		{
			int choose;
			cout << "do you want insert disk << " << current->data.getname() << " >>?" << endl;
			cin >> choose;
			if (choose == 1)
			{
				tray.set_cur_disk(&(current->data));
				return ;
			}
			current = current->next;
		}
		state = "closed";
	}
	else
	{
		cout << "disk " << tray.get_cur_name() << " was ejected" << endl;
		tray.set_cur_disk(NULL);
		state = "open";
	}
}

void Centr::eject_or_insert(list *disks)
{
	eject.press(disks, tray);
}

void Button_next_song::press(disk_tray &tray)
{
	cout << "you pressed " << color << " button" << endl;
	if (tray.getdisk() == NULL)
	{
		cout << "no disk in disk tray" << endl;
		return ;
	}
	tray.getdisk()->getnextsong();
}

void Centr::get_next_song()
{
	next_song.press(tray);
}

void Centr::change_vol(int flag)
{
	if (flag == 0)
		ch_v_down.press(volume);
	else
		ch_v_up.press(volume);
}

string disk_tray::get_cur_name()
{
	return curdisk->getname();
}

string disk::get_cur_song()
{
	return songs[cursong];
}

string disk_tray::get_cur_song()
{
	return curdisk->get_cur_song();
}

void disk_tray::set_cur_disk(disk *d)
{
	curdisk = d;
}

disk* disk_tray::getdisk()
{
	return curdisk;
}
