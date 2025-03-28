//
// Created by 011ko on 01.03.2025.
//

#include <iostream>
#include <unknwn.h>
#include <objbase.h>

#include "interfaces.h"

using namespace std;

int main () {
    cout << "Hello, world!" << endl;

    HRESULT hr;

    cout << "Клиент: получить указатель на IUnknown" << endl;
    IUnknown* pIUnknown = CreateInstance();

    cout << "\nКлиент: получить указатель на IX" << endl;
    // Определяем указатель на интерфейс
    IX* pIX = NULL;
    // Запрашиваем интерфейс IX
    hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IX успешно получен" << endl;
        pIX->Fx(); // Использовать интерфейс IX
    };

    cout << "\nКлиент: получить указатель на IY" << endl;
    IY* pIY = NULL;
    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IY успешно получен" << endl;
        pIY->Fy(); // Использовать интерфейс IY
    };

    cout << "\nКлиент: получить неподдерживаемый интерфейс" << endl;
    IZ* pIZ = NULL;
    hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
    if(SUCCEEDED(hr)) {
        cout << "Клиент: интерфейс IZ успещно получен" << endl;
    } else {
        cout << "Клиент: Не удается получить доступ к интерфейсу IZ" << endl;
    };


    cout << "\nКлиент: получить указатель на IY через IX" << endl;
    IY* pIYfromIX = NULL;
    hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
    if(SUCCEEDED(hr)) {
        cout<< "Клиент: указатель на IY успешно получен" << endl;
        pIYfromIX->Fy();
    } else {
        cout << "Клиент: невозможно получить указатель на IY через IX" << endl;
    }

    cout << "\nКлиент: получить указатель на IUnknown через IY" << endl;
    IUnknown *pIUnknownFromIY = NULL;
    hr = pIY->QueryInterface(IID_IUnknown1, (void **) &pIUnknownFromIY);
    if (SUCCEEDED(hr)) {
        cout << "Равны два ли два указателя?" << endl;
        if (pIUnknownFromIY == pIUnknown) {
            cout << "ДА" << endl;
        } else {
            cout << "НЕТ" << endl;
        }
    }

    // Удалить компонент
    delete pIUnknown;

    return 0;
};