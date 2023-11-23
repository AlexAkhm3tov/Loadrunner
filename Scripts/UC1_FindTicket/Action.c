Action()
{

	lr_start_transaction("UC1_FindTicket");

		GotoHome();
		
		lr_think_time(5);
	
		Login();
		
		lr_think_time(5);
		
		GotoFindTicket();
		
		lr_think_time(5);
	
		FindTicket();
	
		lr_think_time(5);
	
		ChooseTicket();
		
		lr_think_time(5);
	
		LogOut();

	lr_end_transaction("UC1_FindTicket",LR_AUTO);

	return 0;
}