Action()
{

	lr_start_transaction("UC1_FindTicket");

		GotoHome();
		
		lr_think_time(7);
	
		Login();
		
		lr_think_time(13);
		
		GotoFindTicket();
		
		lr_think_time(5);
	
		FindTicket();
	
		lr_think_time(11);
	
		ChooseTicket();
		
		lr_think_time(9);
	
		LogOut();

	lr_end_transaction("UC1_FindTicket",LR_AUTO);

	return 0;
}