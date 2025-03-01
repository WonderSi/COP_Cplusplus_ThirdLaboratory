//
// Created by 011ko on 01.03.2025.
//

#include "interfaces.h"

// Определение IID
// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IX =
        {0x32bb8320, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IY =
        {0x32bb8321, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

// {32bb8322-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IZ =
        {0x32bb8322, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

// {32bb8323-b41b-11cf-a6bb-0080c7b2d682}
const IID IID_IUnknown1 =
        {0x32bb8323, 0xb41b, 0x11cf,
         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};

ULONG __stdcall CA::AddRef() {
    return 0;
};

ULONG __stdcall CA::Release() {
    return 0;
};

HRESULT __stdcall CA::QueryInterface(const IID &iid, void **ppv) {
    if (iid == IID_IUnknown1) {
        cout << "QueryInterface: возвращаю указатель на IUnknown" << endl;
        *ppv = static_cast<IX *>(this);
    } else if (iid == IID_IX) {
        cout << "QueryInterface: возвращаю указатель на IX" << endl;
        *ppv = static_cast<IX *>(this);
    } else if (iid == IID_IY) {
        cout << "QueryInterface: возвращаю указатель на IY" << endl;
        *ppv = static_cast<IY *>(this);
    } else {
        cout << "Интерфейс не поддерживается" << endl;
        *ppv = NULL;
        return E_NOINTERFACE;
    }
    reinterpret_cast<IUnknown *>(*ppv)->AddRef();
    return S_OK;
};

void __stdcall CA::Fx() { cout << "CA::Fx" << endl; };

void __stdcall CA::Fy() { cout << "CA::Fy" << endl; };

// Функция создания компонента
IUnknown* CreateInstance() {
    IUnknown* pI = static_cast<IX*>(new CA);
    pI->AddRef();
    return pI;
};