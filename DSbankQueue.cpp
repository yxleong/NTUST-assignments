#include <iostream>
#include <vector>

struct customer
{
	std::string name = "";
	int arrive_time = 0;
	int time_required = 0;
	int complete_time = 0;
	int deskID = 0;
};

struct counter
{
	std::vector<customer> queue = {};
	int queue_length = 0;
	int front_complete_time = 0;
	int rear_complete_time = 0;
	int total_cust = 0;
};

bool isEmpty(std::vector<counter> desk)
{
	for (int i = 0; i < desk.size(); i++)
	{
		if (desk[i].queue_length != 0)
		{
			return false;
		}
	}
	return true;
}

std::vector<counter> passTime(std::vector<counter> desk)
{
	for (unsigned int i = 0; i < desk.size(); i++)
	{
		if (desk[i].queue.size() != 0 && desk[i].queue_length > 0)
		{
			desk[i].front_complete_time = desk[i].queue[desk[i].total_cust].complete_time;
		}
	}
	return desk;
}

std::vector<counter> chooseCounter(std::vector<counter> desk, customer cust)
{
	int short_desk = desk[0].queue_length,
		short_deskID = 0;
	for (unsigned int i = 0; i < desk.size(); i++)
	{
		if (desk[i].queue_length < short_desk)
		{
			short_desk = desk[i].queue_length;
			short_deskID = i;
		}
	}
	desk[short_deskID].queue.push_back(cust);
	desk[short_deskID].queue_length++;
	desk[short_deskID].queue[desk[short_deskID].queue.size() - 1].deskID = short_deskID;

	if (desk[short_deskID].rear_complete_time > cust.arrive_time)
	{
		desk[short_deskID].queue[desk[short_deskID].queue.size() - 1].complete_time
			= desk[short_deskID].rear_complete_time + cust.time_required;

		desk[short_deskID].rear_complete_time
			= desk[short_deskID].rear_complete_time + cust.time_required;
	}
	else
	{
		desk[short_deskID].queue[desk[short_deskID].queue.size() - 1].complete_time
			= cust.arrive_time + cust.time_required;

		desk[short_deskID].rear_complete_time
			= cust.arrive_time + cust.time_required;
	}

	return desk;
}

std::vector<counter> insertCust(std::vector<counter> desk, std::vector<customer> queue, int time)
{
	for (unsigned int i = 0; i < queue.size(); i++)
	{
		if (queue[i].arrive_time == time)
			desk = chooseCounter(desk, queue[i]);
	}
	return desk;
}

std::vector<counter> output(std::vector<counter> desk, int time)
{
	for (unsigned int i = 0; i < desk.size(); i++)
	{
		if (desk[i].front_complete_time <= time &&
			desk[i].queue.size() >= desk[i].queue_length &&
			desk[i].queue_length > 0)
		{
			std::cout << desk[i].queue[desk[i].total_cust].name << " "
				<< desk[i].queue[desk[i].total_cust].complete_time << " "
				<< desk[i].queue[desk[i].total_cust].deskID << std::endl;
			desk[i].total_cust++;
			desk[i].queue_length--;

			if (desk[i].queue_length != 0)
			{
				desk[i].front_complete_time = desk[i].queue[desk[i].total_cust].complete_time;
			}
			i--;
		}
	}
	return desk;
}

int main(void)
{
	int time = 0;

	int counter_num = 0;
	std::cin >> counter_num;

	std::vector<counter> bank_counter;
	for (unsigned int i = 0; i < counter_num; i++)
	{
		bank_counter.push_back(counter());
	}

	std::vector<customer> queue;
	int last_arrive = 0;
	while (1) // Ctrl+z
	{
		customer input;

		std::cin >> input.name;
		if (input.name.size() != 0)
		{
			std::cin >> input.arrive_time;
			if (input.arrive_time > last_arrive)
			{
				last_arrive = input.arrive_time;
			}
			std::cin >> input.time_required;
			queue.push_back(input);
		}
		else
			break;
	}

	while (1)
	{
		time++;
		bank_counter = output(bank_counter, time);
		bank_counter = insertCust(bank_counter, queue, time);
		bank_counter = passTime(bank_counter);

		if (isEmpty(bank_counter) && time > last_arrive)
			break;
	}
	return 0;
}
