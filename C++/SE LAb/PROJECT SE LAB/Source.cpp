//cout << "\nhi fight...started" << endl;
///*if (Type == 'r' && obj.Type == 'p')
//	obj.strength = strength * 2;
//else if (Type == 'r' && obj.Type == 's')
//	strength = obj.strength * 2;
//else if (Type == 'p' && obj.Type == 's')
//	obj.strength = strength * 2;
//else if (Type == 'p' && obj.Type == 'r')
//	strength = obj.strength * 2;
//else if (Type == 's' && obj.Type == 'r')
//	obj.strength = strength * 2;
//else if (Type == 's' && obj.Type == 'p')
//	strength = obj.strength * 2;*/
//
// 
// 
//int TemStrP, TemStrS, TemStrR;
//if (Type == 'r' && obj.Type == 'p') {
//	TemStrP = obj.strength;
//	cout << "\nr&P\n";
//	TemStrR = strength / 2;
//	if (TemStrP < TemStrR)
//		return true;
//	else if (TemStrP > TemStrR)
//		return false;
//}
//else if (Type == 'r' && obj.Type == 's') {
//	TemStrS = obj.strength;
//	TemStrR = strength * 2;
//	cout << "\nR&S";
//	if (TemStrS < TemStrR)
//		return true;
//	else if (TemStrS > TemStrR)
//		return false;
//}
//else if (Type == 's' && obj.Type == 'p') {
//	TemStrP = obj.strength;
//	TemStrS = strength * 2;
//	cout << "\nS&P";
//	if (TemStrP < TemStrS)
//		return true;
//	else if (TemStrP > TemStrS)
//		return false;
//}
//else if (Type == 's' && obj.Type == 'r') {
//	TemStrR = obj.strength;
//	TemStrS = strength / 2;
//	cout << "\nS&R";
//	if (TemStrR < TemStrS)
//		return true;
//	else if (TemStrR > TemStrS)
//		return false;
//}
//else if (Type == 'p' && obj.Type == 's') {
//	TemStrS = obj.strength;
//	TemStrP = strength / 2;
//	cout << "\nP&S";
//
//	if (TemStrP > TemStrS)
//		return true;
//	else if (TemStrP < TemStrS)
//		return false;
//}
//else if (Type == 'p' && obj.Type == 'r') {
//	TemStrR = obj.strength;
//	TemStrP = strength * 2;
//	cout << "\nP&r";
//	if (TemStrR < TemStrP)
//		return true;
//	else if (TemStrR > TemStrP)
//		return false;
//}
//else {
//	cout << "There is an error in this code...!\n";
//	return 0;
//}
//cout << "fight ended";