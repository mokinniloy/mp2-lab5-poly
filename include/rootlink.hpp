#pragma once

#include <iostream>
#include <datvalue.hpp>

class TRootLink;
typedef TRootLink *PTRootLink;

class TRootLink
{
protected:
  PTRootLink pNext; // указатель на следующее звено
public:
  TRootLink(PTRootLink pN = NULL) { pNext = pN; }

  PTRootLink GetNextLink() { return pNext; }
  void SetNextLink(PTRootLink pLink) { pNext = pLink; }
  void InsNextLink(PTRootLink pLink);

  virtual void SetDatValue(PTDatValue pVal) = 0;
  virtual PTDatValue GetDatValue() = 0;

  friend class TDatList;
};