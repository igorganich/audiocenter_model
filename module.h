#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class disk
{
	private:
		string name;
		int size;
		int cursong;
		string *songs;
	public:
		disk();
		string getname();
		void getnextsong();
		string get_cur_song();
		~disk()
		{
			delete[] songs;
		}
};

struct list
{
	disk	data;
	list	*next;
};

class Button
{
	protected:
		string color;
	public:
		Button();
		virtual void getinfo() = 0;
//		virtual disk press(disk tem) = 0;
//		virtual int press(int curvolume) = 0;
//		virtual string press(string cursong) = 0;
	//	~Button() = 0;
};

class disk_tray
{
	private:
		disk *curdisk;
	public:
		disc_tray()
		{
			curdisk = NULL;
		}
		disk *getdisk();
		string get_cur_name();
		string get_cur_song();
		void set_cur_disk(disk *d);
};

class Button_eject_insert:public Button
{
	private:
		string state;
	public:
		Button_eject_insert();
		void press(list* &disks, disk_tray &tray);
		void getinfo()
		{
			cout << "color is" << color << " state is " << state << endl;
		}
};

class Button_change_volume_up:public Button
{
	public:
		Button_change_volume_up();
		void press(int &curvolume);
		void getinfo()
		{
			cout << "color is" << color << endl;
		}
};

class Button_change_volume_down:public Button
{
	public:
		Button_change_volume_down();
		void press(int &curvolume);
		void getinfo()
		{
			cout << "color is" << color << endl;
		}
};

class Button_next_song:public Button
{
	public:		
		void press(disk_tray &tray);
		Button_next_song();
		void getinfo()
		{
			cout << "color is" << color << endl;
		}
};

class Centr
{
	private:
		Button_eject_insert eject;
		Button_change_volume_up ch_v_up;
		Button_change_volume_down ch_v_down;
		Button_next_song next_song;
		disk_tray tray;
		int volume;
	public:
		Centr();
		void change_vol(int flag);
		void getinfo();
		void eject_or_insert(list *disks);
		void get_next_song();
};
