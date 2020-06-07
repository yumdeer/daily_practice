


//---------------------------------------------------------------------------
// Digital IO Functions -----------------------------------------------------
//---------------------------------------------------------------------------

extern "C"  __declspec(dllexport) int DIO_Init();
extern "C"  __declspec(dllexport) int DIO_SetDirection(unsigned char ucData);
extern "C"  __declspec(dllexport) int DIO_Write(unsigned char ucData);
extern "C"  __declspec(dllexport) unsigned char DIO_Read();

extern "C"  __declspec(dllexport) int DIO2_Init();
extern "C"  __declspec(dllexport) int DIO2_SetDirection(unsigned char ucData);
extern "C"  __declspec(dllexport) int DIO2_Write(unsigned char ucData);
extern "C"  __declspec(dllexport) unsigned char DIO2_Read();

