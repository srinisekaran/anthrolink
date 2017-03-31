// Anthrolink
// March 13, 2017

// RF Solid Switch from Mini-Circuits
// minicircuits.com/softwaredownload/Prog_Manual-Solid_State_Switch.pdf

// Create new switch object referencing DLL 
USB_Digital_Switch ^MyPTE1 = gcnew USB_Digital_Switch();

int steps_number = 4; 

// Connection Routine
status = MyPTE1->Connect();
if (MyPTE1->GetUSBConnectionStatus() == 1) {
	MessageBox::Show("USB Connection is valid.")
}

if (MyPTE1->Read_ModelName(ModelName) > 0 ) {
	MessageBox::Show("The connected switch is " + ModelName);
}

// Enable continuous mode
mode = MyPTE1->GetSequence_ContinuousMode();
if (mode !== 1 ) {
	status = MyPTE1->SetSequence_ContinuousMode(1);
}

// Connect COM to port 1
status = MyPTE1->Set_SP4T_COM_To(1);


// Sequence Initialization - 4 Steps
status = MyPTE1->SetSequence_NoOfSteps(steps_number);

// Step 0; Com Connect to Port 1; Dwell for 5 ms
status = MyPTE1->SetSequence_Step(0, 1, 5, 1);
status = MyPTE1->SetSequence_Step(1, 4, 10, 1);
status = MyPTE1->SetSequence_Step(2, 3, 5, 1);
status = MyPTE1->SetSequence_Step(3, 2, 10, 1);

// Last param: 0 (us), 1 (ms), 2 (s)
// Switches between Ports 1 - 4
// for (int i = 0; i < steps_number; i++)
// {
//	if (status == 1) {
//		status = MyPTE1->SetSequence_Step(i, i, 5, 1);
//  }
// }

// Start Sequence
status = MyPTE1->SetSequence_ON();

// Disconnect
// MyPTE1->Disconnect();
