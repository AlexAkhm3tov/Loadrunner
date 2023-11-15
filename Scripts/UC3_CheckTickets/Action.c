Action()
{

	lr_start_transaction("UC3_CheckTickets");

		GotoHome();
		
		lr_think_time(7);
	
		Login();
		
		lr_think_time(7);
		
		CheckTickets();
		
		lr_think_time(11);
		
		LogOut();
		
	lr_end_transaction("UC3_CheckTickets",LR_AUTO);

	return 0;
}