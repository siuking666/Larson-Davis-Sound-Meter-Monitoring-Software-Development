/**************************************************************************//**
 * @file IBindingList.h
 * @brief Native Wrapper for Managed type IBindingList.
 * @version 1.1.0
 * @author Kevin Lawrence
 ******************************************************************************
 * @section License
 * <b> (C)Copyright 2023 Larson Davis, A PCB Piezotronics Div.</b>
 * <b> Confidential </b>
 *
******************************************************************************/ 


#ifndef _IBINDING_LIST_H
#define _IBINDING_LIST_H
#include <IList.h>
#include <EListSortDirection.h>
namespace LarsonDavis
{
	namespace Native
	{
		class LDAPI IList;

		class LDAPI IBindingList : public virtual IList
		{
		public: // This section is the available interface
			// This does not create a copy of the underlying object but simply clones the wrapper.
			IBindingList(const IBindingList& other);
			//Will destry the wrapper and remove the managed referece so GC can collect the object once all wrappers are destroyed.
			virtual ~IBindingList(void);
			virtual void RemoveSort(void);
			virtual bool AllowNew(void);
			virtual bool AllowEdit(void);
			virtual bool AllowRemove(void);
			virtual bool SupportsChangeNotification(void);
			virtual bool SupportsSearching(void);
			virtual bool SupportsSorting(void);
			virtual bool IsSorted(void);
			virtual EListSortDirection SortDirection(void);
#ifdef MAKEDLL
		public: // This is for internal use
			IBindingList(){};
			IBindingList(nullptr_t none);
			virtual void* GetId() const { return (void*)this; }
#endif // MAKEDLL
		};
	}
}
#endif // _IBINDING_LIST_H
