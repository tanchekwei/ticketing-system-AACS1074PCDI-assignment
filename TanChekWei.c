#include <stdio.h>
#include <stdlib.h>
#include <windows.h>						//To use sleep() function
#include <math.h>							//To use fabs() function
#pragma warning (disable:4996)				//To use scanf() function

#define class0_adult 30.00					//Define constant is used to define all price for
#define class0_student 20.00				//adult, student and child for all class
#define class0_child 15.00
#define class1_adult 26.00
#define class1_student 17.00
#define class1_child 13.00
#define class2_adult 20.00
#define class2_student 14.00
#define class2_child 10.00
#define class0_total_seat 15				//Define constant is used to define total seat for
#define class1_total_seat 15				//class 0, 1 and 2
#define class2_total_seat 30
#define all_class_total_seat 60

//all variables are declare at here.
char movie_name[31], movie_time[31], next;

int class_required, adult_seat, child_seat, student_seat, adult_seat_counter = 0, child_seat_counter = 0,
student_seat_counter = 0, total_seat, total_seat_sold = 0, adult_seat_counter_for_report = 0,
student_seat_counter_for_report = 0, child_seat_counter_for_report = 0;

//Array is used to reduce variables have to declare.
int class_seat_no[] = { 000, 100, 200 }, class_seat[] = { 15, 15, 30 }, class_counter_for_pct[3],
class_seat_left[3], class_seat_counter[3], class_ticket_counter[3];

double adult_seat_price, child_seat_price, student_seat_price, total_seat_amount, cash_payment, balance_amount,
adult_seat_amount, student_seat_amount, child_seat_amount, adult_sales_total = 0, student_sales_total = 0,
child_sales_total = 0;

//Function type and name is declare here:
void clear_screen();
void flush();
void print_logo();
void welcome();
char input_movie_name();
char input_movie_time();
int get_class();
int get_number_seat();
void bill_calculation();
int	seat_calculation();
void print_ticket();
char next_customer();
void sales_report();
void ending_message();

void main()
{
	print_logo();
	welcome();
	input_movie_name();
	input_movie_time();
	get_class();
	get_number_seat();
	bill_calculation();
	seat_calculation();
	print_ticket();
	next_customer();
}

void print_logo()
{
	system("COLOR 70");								//To print out black colour text with white background.
	printf("\n\n\n			_______ _    ____   ____ _\n");		//TARCinemax logo design ~
	printf("			|_   _|/ \\  |  _ \\ / ___(_)_ __   ___ _ __ ___   __ ___  __		\n");
	printf("			  | | / _ \\ | |_) | |   | | '_ \\ / _ \\ '_ ` _ \\ / _` \\ \\/ /	\n");
	printf("			  | |/ ___ \\|  _ <| |___| | | | |  __/ | | | | | (_| |>  <			\n");
	printf("			  |_/_/   \\_\\_| \\_\\\\____|_|_| |_|\\___|_| |_| |_|\\__,_/_/\\_\\	\n\n");
	printf("		---------------------------------------------------------------------------\n\n");
}

void welcome()
{
	char answer;

	printf("				Welcome to TARCinemx !\n");					//Greeting message
	//Ask user enter 'Y' to purchase tickets, 'N' to exit program.
	printf("				Do you want to purchase some tickets ?\n");
	printf("				If Yes, please press 'Y' to continue.\n");
	printf("				If No , please press 'N' to exit >>> ");
	scanf("%c", &answer);

	if (answer == 'Y' || answer == 'y')
	{
		clear_screen();											//This clear_screen() function is used to clear screen.
	}
	else if (answer == 'N' || answer == 'n')
	{
		printf("\n\n				Thank you for visiting us !!!");
		//Sleep() function in this statement is to wait 1.5 seconds
		Sleep(1500);													//before execute exit() function.
		exit(0);														//exit() function is used to exit program.
	}
	else
	{
		flush();
		clear_screen();
		printf("\n\n				Please only enter 'Y' or 'N'.\n");	//Prompt user to enter Y or N only, 
		print_logo();													//then print logo and print welcome message again,
		welcome();														//to give user chance to enter again.
	}
	flush();															//flush function is used to clear buffer in stdin.
}

char input_movie_name()
{
	int movie_name_code;

	print_logo();

	printf("				List of movie available now:\n");			//Menu is used to let user choose movie they like,
	printf("				1. Guardians of the Galaxy Vol. 2\n");		//to eliminate the inconvenient of typing movie name.
	printf("				2. Transformers: The Last Knight\n");		//User have to enter movie code showed to select movie they want.
	printf("				3. Thor: Ragnarok\n");
	printf("				4. World War Z 2\n");
	printf("				5. Fast 8\n");
	printf("				6. Quit this program now!\n\n");

	printf("			Please enter code of movie you like to watch (1 to 5): ");
	scanf("%d", &movie_name_code);

	switch (movie_name_code)									//switch() in here is used determine which movie name
	{															// have to copy movie_name variable.
	case 1:
		//strcpy() function is used to assign/copy string to a variable
		strcpy(movie_name, "Guardians of the Galaxy Vol. 2");
		break;
	case 2:
		strcpy(movie_name, "Transformers: The Last Knight");
		break;
	case 3:
		strcpy(movie_name, "Thor: Ragnarok");
		break;
	case 4:
		strcpy(movie_name, "World War Z 2");
		break;
	case 5:
		strcpy(movie_name, "Fast 8");
		break;
	case 6:
		printf("\n\n				Thank you for visiting us !!!");
		Sleep(1500);
		exit(0);
		break;
	default:
		flush();
		clear_screen();
		printf("\n\n				Please only enter 1 to 6.\n");	//give user chance enter movie code again
		input_movie_name();											//if user enter something other than 1 to 5.
	}
	clear_screen();
	return movie_name;
}

char input_movie_time()
{
	int movie_time_code;

	print_logo();

	printf("			You have chosen \"%s\" movie.\n\n", movie_name);//To let user know what movie they have choosen.
	printf("				List of time available :\n");				//To let user choose the time they prefer.
	printf("				1. Friday  6.00 p.m.\n");
	printf("				2. Friday  7.00 p.m.\n");
	printf("				3. Friday  8.00 p.m.\n");
	printf("				4. Friday  9.00 p.m.\n");
	printf("				5. Friday 10.00 p.m.\n");
	printf("				6. Reselect movie.\n");
	printf("				7. Quit this program now!\n\n");

	printf("			Please enter code of time you prefer (1 to 5): ");//Prompt user enter code.
	scanf("%d", &movie_time_code);
	//Used to determine which string have to be copy to movie_time.
	switch (movie_time_code)
	{
	case 1:
		strcpy(movie_time, "Friday  6.00 p.m.");
		break;
	case 2:
		strcpy(movie_time, "Friday  7.00 p.m.");
		break;
	case 3:
		strcpy(movie_time, "Friday  8.00 p.m.");
		break;
	case 4:
		strcpy(movie_time, "Friday  9.00 p.m.");
		break;
	case 5:
		strcpy(movie_time, "Friday 10.00 p.m.");
		break;
	case 6:
		clear_screen();
		input_movie_name();
		clear_screen();
		input_movie_time();
		break;
	case 7:
		printf("\n\n				Thank you for visiting us !!!");
		Sleep(1500);
		exit(0);
		break;
	default:
		flush();
		clear_screen();
		printf("\n\n				Please only enter 1 to 7.\n");
		input_movie_time();
	}
	flush();
	clear_screen();
	return movie_time;
}

int get_class()
{
	print_logo();
	//movie time user have chosen shown to them.
	printf("		You have chosen \"%s\" movie on %s\n\n", movie_name, movie_time);
	printf("\n				Counter is now Open for Selling of Tickets\n\n");		//Now get class user needed.
	printf("					Seats Available:\n");
	printf("					Class 0 - %d\n", class_seat[0]);
	printf("					Class 1 - %d\n", class_seat[1]);
	printf("					Class 2 - %d\n\n", class_seat[2]);
	printf("				Class Required (0, 1, 2)?\n");
	printf("			   *Enter '3' to reselect time* : ");
	scanf("%d", &class_required);

	switch (class_required)
	{
	case 0:
		adult_seat_price = class0_adult;						//After get class, assign price of adult seat,
		child_seat_price = class0_child;						//child seat and student seat for the class user chose.
		student_seat_price = class0_student;
		break;
	case 1:
		adult_seat_price = class1_adult;
		child_seat_price = class1_child;
		student_seat_price = class1_student;
		break;
	case 2:
		adult_seat_price = class2_adult;
		child_seat_price = class2_child;
		student_seat_price = class2_student;
		break;
	case 3:
		clear_screen();
		input_movie_time();
		get_class();
		break;
	default:
		flush();
		clear_screen();
		printf("\n\n				Please only enter 0 to 3.\n");
		get_class();
	}
	clear_screen();
	return class_required, adult_seat_price, child_seat_price, student_seat_price;
}

int get_number_seat()
{
	print_logo();
	//Added detail of class user chose
	printf("		You have chosen class %d \"%s\" movie on %s\n\n", class_required, movie_name, movie_time);
	printf("				Number of Adult Seat required				: ");//Prompt user to enter adult seat required,
	scanf("%d", &adult_seat);												//child seat required and student seat required.
	printf("\n\n				Number of Child Seat required\n");
	printf("					(Children must be below 12 years old)		: ");
	scanf("%d", &child_seat);
	printf("\n\n				Number of Student Seat required : \n");
	printf("					(Must show student registration cards)		: ");
	scanf("%d", &student_seat);

	total_seat = adult_seat + child_seat + student_seat;		//Calculate total seats needed

	switch (class_required)							//Check whether the seats entered by user is exceed available seats
	{
	case 0:
		if (total_seat > class_seat[0])
		{
			clear_screen();
			printf("\n\n				We only left %d seats for this class", class_seat[0]);		//Show number of seat available to user.
			get_class();
			get_number_seat();
		}
		break;
	case 1:
		if (total_seat > class_seat[1])
		{
			clear_screen();
			printf("\n\n				We only left %d seats for this class", class_seat[1]);
			get_class();
			get_number_seat();
		}
		break;
	case 2:
		if (total_seat > class_seat[2])
		{
			clear_screen();
			printf("\n\n				We only left %d seats for this class", class_seat[2]);
			get_class();
			get_number_seat();
		}
		break;
	}
	clear_screen();
	return adult_seat, child_seat, student_seat;
}
void bill_calculation()
{
	print_logo();
	adult_seat_amount = adult_seat * adult_seat_price;							//Amount need to pay by user calculate here
	student_seat_amount = student_seat * student_seat_price;					//for 3 type of seat.
	child_seat_amount = child_seat * child_seat_price;
	total_seat_amount = adult_seat_amount + student_seat_amount + child_seat_amount;	//Total amount need to pay by user calculate here.

	printf("			You have chosen %2d adult seat, %2d child seat and %2d student seat for\n", adult_seat, child_seat, student_seat);
	printf("			class %d \"%s\" movie on %s\n\n", class_required, movie_name, movie_time);

	printf("\n				Bill Calculation - Class %d\n", class_required);		//Print out the bill.
	printf("			   ------------------------------------\n");
	printf("\n				Number of Adults	= %2d @ RM %6.2f = RM %6.2f\n", adult_seat, adult_seat_price, adult_seat_amount);
	printf("\n				Number of Students	= %2d @ RM %6.2f = RM %6.2f\n", student_seat, student_seat_price, student_seat_amount);
	printf("\n				Number of Children	= %2d @ RM %6.2f = RM %6.2f\n", child_seat, child_seat_price, child_seat_amount);
	printf("\n				Total to Pay 		=  RM %6.2f\n", total_seat_amount);
	printf("\n				*Enter -999 to cancel this trade*\n");
	printf("\n				Cash Payment            =  RM ");	//Cash paid is enter by user.
	scanf("%lf", &cash_payment);
	if (cash_payment == -999)									//user can enter -999 to quit program
	{
		printf("\n\n				Thank you for visiting us !!!");
		Sleep(1500);
		exit(0);
	}

	if (cash_payment < 0)										//user is not allowed to enter negative integer
	{
		clear_screen();
		printf("\n\n				Please enter positive integer only.");
		bill_calculation();
	}

	balance_amount = cash_payment - total_seat_amount;			//Calculate the balance after minus total amount 
																//have to pay by user with the amount cash user paid.
	if (balance_amount >= 0)									//If user paid enough cash, show the change due.
	{
		printf("\n				Change Due		=  RM %6.2f", balance_amount);
	}
	else if (balance_amount < 0)								//If user paid not enough cash,
	{															//prompt user paid more cash.
		do
		{
			printf("\n				You have to pay more RM%6.2f !", fabs(balance_amount));
			//fabs() function used here to temporary change
			printf("\n				Cash Payment		=  RM ");	//negative sign to positive sign for showing to user.
			scanf("%lf", &cash_payment);							//math header file must include to user fabs() function.
			if (cash_payment == -999)
			{
				printf("\n\n				Thank you for visiting us !!!");
				Sleep(1500);
				exit(0);
			}

			if (cash_payment < 0)
			{
				clear_screen();
				printf("\n\n				Please enter positive integer only.");
				bill_calculation();
			}
			//assign value in balance_amount (which is negative value) to total_seat_amount
			total_seat_amount = balance_amount;
			//So, balance can be calculate again by adding cash paid with total_seat_amount.
			//For example, 200 (cash payment) + - 198 (total have to pay) = 2 (change due)
			balance_amount = cash_payment + total_seat_amount;
			total_seat_amount = balance_amount;					//Updating the total have to pay
		} while (balance_amount < 0);
	}
	else
	{
		clear_screen();
		printf("				Please enter number only.\n");	//Data type other than number cannot enter by user.
		bill_calculation();
	}
	printf("\n				Change Due		=  RM %6.2f", balance_amount);//Showed change due after user paid enough cash.
}

int seat_calculation()	//This function used to calculate number of seat purchased and sales for
{						//adult seat, student seat and child seat.
	student_seat_counter = student_seat;
	student_seat_counter_for_report += student_seat_counter;
	student_seat_counter = 0;

	adult_seat_counter = adult_seat;
	adult_seat_counter_for_report += adult_seat_counter;
	adult_seat_counter = 0;

	child_seat_counter = child_seat;
	child_seat_counter_for_report += child_seat_counter;
	child_seat_counter = 0;
	//Total up all adult, child and student sales.
	adult_sales_total += adult_seat_amount;
	child_sales_total += child_seat_amount;
	student_sales_total += student_seat_amount;

	switch (class_required) //Also calculate seat left for class 0, 1 and 2.
	{
	case 0:
		for (class_seat_counter[0] = 0; class_seat_counter[0] < total_seat; class_seat_counter[0]++);
		class_counter_for_pct[0] += (double)class_seat_counter[0];
		break;
	case 1:
		for (class_seat_counter[1] = 0; class_seat_counter[1] < total_seat; class_seat_counter[1]++);
		class_counter_for_pct[1] += (double)class_seat_counter[1];
		break;
	case 2:
		for (class_seat_counter[2] = 0; class_seat_counter[2] < total_seat; class_seat_counter[2]++);
		class_counter_for_pct[2] += (double)class_seat_counter[2];
	}

	class_seat_left[0] = class_seat[0] - class_seat_counter[0];
	class_seat[0] = class_seat_left[0];
	class_seat_left[1] = class_seat[1] - class_seat_counter[1];
	class_seat[1] = class_seat_left[1];
	class_seat_left[2] = class_seat[2] - class_seat_counter[2];
	class_seat[2] = class_seat_left[2];

	return	class_seat_counter[0], class_seat_counter[1], class_seat_counter[2], student_seat_counter, adult_seat_counter, child_seat_counter,
		class_seat_left[0], class_seat_left[1], class_seat_left[2], class_seat[0], class_seat[1], class_seat[2], adult_sales_total,
		child_sales_total, student_sales_total;
}

void print_ticket()
{
	printf("\n\n\n				Here are your tickets: \n\n");	//Sleep() function used by including windows header file.
	switch (class_required)
	{
	case 0:						//If user choose class 0, execute these statements.
		if (adult_seat > 0)		//If user entered adult seat more than 0, adult seat ticket have to print out.
		{
			for (class_ticket_counter[0] = 0; class_ticket_counter[0] < adult_seat; class_ticket_counter[0]++)
			{				//class_ticket_counter is used to control the loop.
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket				ADULT - Class 0\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[0], class0_adult);
				printf("		===============================================================\n\n\n\n");
			}
		}
		if (child_seat > 0)	//"if" used instead of "else if" to check 3 type of seat one by one.
		{
			for (class_ticket_counter[0] = 0; class_ticket_counter[0] < child_seat; class_ticket_counter[0]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket				CHILD - Class 0\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[0], class0_child);
				printf("		===============================================================\n\n\n\n");
			}
		}
		if (student_seat > 0)
		{
			for (class_ticket_counter[0] = 0; class_ticket_counter[0] < student_seat; class_ticket_counter[0]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket			      STUDENT - Class 0\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[0], class0_student);
				printf("		===============================================================\n\n\n\n");
			}
		}
		break;

	case 1:						//if user choose class 1, execute these statements.
		if (adult_seat > 0)
		{
			for (class_ticket_counter[1] = 0; class_ticket_counter[1] < adult_seat; class_ticket_counter[1]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket				ADULT - Class 1\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[1], class1_adult);
				printf("		===============================================================\n\n\n\n");
			}
		}
		if (child_seat > 0)
		{
			for (class_ticket_counter[1] = 0; class_ticket_counter[1] < child_seat; class_ticket_counter[1]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket				CHILD - Class 1\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[1], class1_child);
				printf("		===============================================================\n\n\n\n");
			}
		}
		if (student_seat > 0)
		{
			for (class_ticket_counter[1] = 0; class_ticket_counter[1] < student_seat; class_ticket_counter[1]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket			      STUDENT - Class 1\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[1], class1_student);
				printf("		===============================================================\n\n\n\n");
			}
		}
		break;
	case 2:						//if user choose class 2, execute these statements.
		if (adult_seat > 0)
		{
			for (class_ticket_counter[2] = 0; class_ticket_counter[2] < adult_seat; class_ticket_counter[2]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket				ADULT - Class 2\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[2], class2_adult);
				printf("		===============================================================\n\n\n\n");
			}
		}
		if (child_seat > 0)
		{
			for (class_ticket_counter[2] = 0; class_ticket_counter[2] < child_seat; class_ticket_counter[2]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket				CHILD - Class 2\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[2], class2_child);
				printf("		===============================================================\n\n\n\n");
			}
		}
		if (student_seat > 0)
		{
			for (class_ticket_counter[2] = 0; class_ticket_counter[2] < student_seat; class_ticket_counter[2]++)
			{
				printf("		===============================================================\n\n");
				printf("		TARCinemax Ticket			      STUDENT - Class 2\n\n");
				printf("		Movie			:	%s\n", movie_name);
				printf("		Date / Time		:	%s\n\n", movie_time);
				printf("		Seat No: %03d				          Price : %.2f\n\n", ++class_seat_no[2], class2_student);
				printf("		===============================================================\n\n\n\n");
			}
		}
	}
	//if there is no more seat for sold, redirecting to sales report.
	if (class_seat[0] == 0 && class_seat[1] == 0 && class_seat[2] == 0)
	{
		printf("		There is no seat available for sold.\n\n\n");
		Sleep(1000);
		printf("		Redirecting to Sales Report ......\n");
		Sleep(2000);
		sales_report();
		ending_message();
	}
}

char next_customer()
{
	printf("					Seats Still Available:\n");	//Show the seat left
	printf("					Class 0 - %d\n", class_seat_left[0]);
	printf("					Class 1 - %d\n", class_seat_left[1]);
	printf("					Class 2 - %d\n\n", class_seat_left[2]);
	flush();
	printf("		Next Customer (Y/N) ? > ");		//Ask whether is next customer or not.
	scanf("%c", &next);
	switch (next)
	{
	case 'Y':										//if yes, program will run from get_class() function
	case 'y':										//to next_customer() function.
		class_seat_counter[0] = 0;
		class_seat_counter[1] = 0;
		class_seat_counter[2] = 0;
		clear_screen();
		get_class();
		get_number_seat();
		bill_calculation();
		seat_calculation();
		print_ticket();
		next_customer();
		break;
	case 'N':										//if no, sales report is show
	case 'n':
		sales_report();
		ending_message();
		break;
	default:										//other than 'y', 'Y', 'n' and 'N', default statements execute.
		clear_screen();
		printf("\n\n\n					Please enter 'Y' or 'N' only.");
		print_logo();
		next_customer();
	}
	flush();
	return next;
}

void sales_report()
{	//Percentage of each class sold is calculate here.
	double class_pct_sold[3], total_pct_sold, total_sales;

	class_pct_sold[0] = ((double)(class_counter_for_pct[0] / (double)class0_total_seat) * 100.00);
	class_pct_sold[1] = ((double)(class_counter_for_pct[1] / (double)class1_total_seat) * 100.00);
	class_pct_sold[2] = ((double)(class_counter_for_pct[2] / (double)class2_total_seat) * 100.00);
	total_seat_sold = class_counter_for_pct[0] + class_counter_for_pct[1] + class_counter_for_pct[2];//Total seat is calculate.
	total_pct_sold = ((double)total_seat_sold / 60.00 * 100.00);						//Total percentage sold is calculate.
	total_sales = adult_sales_total + child_sales_total + student_sales_total;			//Total sales is calculate.
	printf("\n\n	        ===================================================================================\n");
	printf("						Ticket Sales Report\n\n");
	printf("		Movie Title:	%s\n", movie_name);
	printf("		Date / Time:	%s\n\n", movie_time);
	printf("		Seat Occupancy For Each Class:\n\n");
	printf("				Total Seats			Sold		   Percentage Sold\n");
	printf("		Class 0		    %d				%2d			  %6.2f %%\n", class0_total_seat, class_counter_for_pct[0], class_pct_sold[0]);
	printf("		Class 1		    %d				%2d			  %6.2f %%\n", class1_total_seat, class_counter_for_pct[1], class_pct_sold[1]);
	printf("		Class 2		    %d				%2d			  %6.2f %%\n", class2_total_seat, class_counter_for_pct[2], class_pct_sold[2]);
	printf("				-----------			---		  ---------------\n");
	printf("		Overall		    %d				%2d			  %6.2f %%\n\n", all_class_total_seat, total_seat_sold, total_pct_sold);
	printf("        -------------------------------------------------------------------------------------------------\n\n");
	printf("		Sales For Each Cinema Goer Type:\n\n");
	printf("   			        Cinema Goer			Seats			Sales (RM)\n");
	printf("   			        Adult			        %2d		            %6.2f\n", adult_seat_counter_for_report, adult_sales_total);
	printf("   			        Child			        %2d			    %6.2f\n", child_seat_counter_for_report, child_sales_total);
	printf("   			        Student			        %2d			    %6.2f\n", student_seat_counter_for_report, student_sales_total);
	printf("   			        -----------			---		   ---------------\n");
	printf("   			        Total			        %2d			    %6.2f\n\n\n", total_seat_sold, total_sales);
	printf("									Press any key to continue !!!");	//print ending message after pressing any key.
	getch(); //get any thing to continue.
}

void ending_message()	//This function is to thank user for purchasing tickets
{
	system("COLOR 57");								//To print out white colour text with purple background.
	clear_screen();
	printf("\n\n\n		 _____ _                 _                        _		  @  @     @  @\n");
	printf("		|_   _| |__   __ _ _ __ | | __  _   _  ___  _   _| |		 @     @ @     @\n");
	printf("		  | | | '_ \\ / _` | '_ \\| |/ / | | | |/ _ \\| | | | |	      	 @      @      @\n");
	printf("		  | | | | | | (_| | | | |   <  | |_| | (_) | |_| |_|		  @            @\n");
	printf("		  |_| |_| |_|\\__,_|_| |_|_|\\_\\  \\__, |\\___/ \\__,_(_)		   @          @\n");
	printf("		                                 |___/               		    @       @\n");
	printf("										      @   @\n");
	printf("										        @\n");

	printf("\n\n\n\n\n\n\n					Thank you for supporting TARCinemax !!!\n\n");
	printf("					Please come again ~ !\n\n");
	Sleep(2000);	//exit the program after 2 seconds.
}

void clear_screen()	//this function is used to clean screen
{
	system("cls");
}

void flush()		//this function is used to clear buffer in stdin
{
	while (getchar() != '\n');
}