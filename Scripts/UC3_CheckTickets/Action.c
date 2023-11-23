Action()
{

	lr_start_transaction("UC3_CheckTickets");

		GotoHome();
		
		lr_think_time(5);
	
		Login();
		
		lr_think_time(5);
		
		CheckTickets();
		
		lr_think_time(5);
		
		LogOut();
		
	lr_end_transaction("UC3_CheckTickets",LR_AUTO);

	return 0;
}