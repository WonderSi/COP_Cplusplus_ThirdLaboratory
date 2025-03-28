//#include <iostream>
//#include <objbase.h>
//#include <unknwn.h>
//
//using namespace std;
//
//// Предварительное объявление идентификаторов итерфейсов
//extern const IID IID_IX;
//extern const IID IID_IY;
//extern const IID IID_IZ;
//extern const IID IID_IUnknown1;
//
//// Определение IID
//// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
//const IID IID_IX =
//        {0x32bb8320, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
//const IID IID_IY =
//        {0x32bb8321, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//const IID IID_IZ =
//        {0x32bb8322, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//const IID IID_IUnknown1 =
//        {0x32bb8323, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//// Интерфейсы
//interface IX : IUnknown {
//    virtual void __stdcall Fx() = 0;
//};
//
//interface IY : IUnknown {
//    virtual void __stdcall Fy() = 0;
//};
//
//interface IZ : IUnknown {
//    virtual void __stdcall Fz() = 0;
//};
//
//// Компонент
//class CA : public IX, public IY {
//    // Реализация методов класса IUnknown
//    virtual ULONG __stdcall AddRef() { return 0; };
//
//    virtual ULONG __stdcall Release() { return 0; };
//
//    virtual HRESULT __stdcall QueryInterface(const IID &iid, void **ppv) {
//        if (iid == IID_IUnknown1) {
//            cout << "QueryInterface: возвращаю указатель на IUnknown" << endl;
//            *ppv = static_cast<IX *>(this); // разве не должно быть <IUnknown*> ?
//        } else if (iid == IID_IX) {
//            cout << "QueryInterface: возвращаю указатель на IX" << endl;
//            *ppv = static_cast<IX *>(this);
//        } else if (iid == IID_IY) {
//            cout << "QueryInterface: возвращаю указатель на IY" << endl;
//            *ppv = static_cast<IY *>(this);
//        } else {
//            cout << "Интерфейс не поддерживается" << endl;
//            *ppv = NULL;
//            return E_NOINTERFACE;
//        }
//        reinterpret_cast<IUnknown *>(*ppv)->AddRef();
//        return S_OK;
//    }
//
//    // Реализация интерфейсов:
//    virtual void __stdcall Fx() {
//        cout << "CA::Fx" << endl;
//    };
//
//    virtual void __stdcall Fy() {
//        cout << "CA::Fy" << endl;
//    };
//};
//
//// ф-ция создания компонента
//IUnknown *CreateInterface() {
//    IUnknown *pI = static_cast<IX *>(new CA);
//    pI->AddRef();
//    return pI;
//}
//
//int main() {
//    cout << "Hello, World!" << endl;
//
//    HRESULT hr;
//
//    cout << "Client: get pointer to IUnknown" << endl;
//    IUnknown *pIUnknown = CreateInterface();
//
//    cout << "\nClient: get pointer to IX" << endl;
//    // определяем указатель на интерфейс
//    IX *pIX = NULL;
//    // запрашиваем интерфейс IX
//    hr = pIUnknown->QueryInterface(IID_IX, (void **) &pIX);
//
//    // проверяем значение результата и используем интерфейс
//    if (SUCCEEDED(hr)) {
//        cout << "Client: IX received successfully" << endl;
//        pIX->Fx(); // использовать интерфейс IX
//    }
//
//    cout << "\nClient: get pointer to IY" << endl;
//    IY *pIY = NULL;
//    hr = pIUnknown->QueryInterface(IID_IY, (void **) &pIY);
//    if (SUCCEEDED(hr)) {
//        cout << "Client: IY received successfully" << endl;
//        pIY->Fy(); // использовать интерфейс IY
//    }
//
//    cout << "\nClient: Get unsupported interface" << endl;
//    IZ *pIZ = NULL;
//    hr = pIUnknown->QueryInterface(IID_IZ, (void **) &pIZ);
//    if (SUCCEEDED(hr)) {
//        cout << "Client: interface IZ get successfully" << endl;
//    } else {
//        cout << "Client: can not get interface IZ" << endl;
//    }
//
//    cout << "\nКлиент: получить указатель на IY через IX" << endl;
//    IY *pIYfromIX = NULL;
//    hr = pIX->QueryInterface(IID_IY, (void **) &pIYfromIX);
//    if (SUCCEEDED(hr)) {
//        cout << "Клиент: указатель на IY получен успешно" << endl;
//        pIYfromIX->Fy();
//    } else {
//        cout << "Клиент: невозможно получить указатель на IY через IX" << endl;
//    }
//
//    cout << "\nКлиент: получить указатель на IUnknown через IY" << endl;
//    IUnknown *pIUnknownFromIY = NULL;
//    hr = pIY->QueryInterface(IID_IUnknown1, (void **) &pIUnknownFromIY);
//    if (SUCCEEDED(hr)) {
//        cout << "Равны два ли два указателя?" << endl;
//        if (pIUnknownFromIY == pIUnknown) {
//            cout << "ДА" << endl;
//        } else {
//            cout << "НЕТ" << endl;
//        }
//    }
//
//    // Удалить компонент
//    delete pIUnknown;
//
//    return 0;
//}