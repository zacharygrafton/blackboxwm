// Windowmenu.hh for Blackbox - an X11 Window manager
// Copyright (c) 1997 - 2000 Brad Hughes (bhughes@tcac.net)
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef   __Windowmenu_hh
#define   __Windowmenu_hh

// forward declaration
class Windowmenu;
class SendtoWorkspaceMenu;

class Blackbox;
class BlackboxWindow;
class Toolbar;

#include "Basemenu.hh"


class Windowmenu : public Basemenu {
private:
  BlackboxWindow *window;
  BScreen *screen;

  class SendtoWorkspacemenu : public Basemenu {
  private:
    Windowmenu *windowmenu;

  protected:
    virtual void itemSelected(int, int);

  public:
    SendtoWorkspacemenu(Windowmenu *);

    void update(void);

    virtual void show(void);
  };

  SendtoWorkspacemenu *sendToMenu;

  friend SendtoWorkspacemenu;


protected:
  virtual void itemSelected(int, int);


public:
  Windowmenu(BlackboxWindow *);
  virtual ~Windowmenu(void);

  inline Basemenu *getSendToMenu(void) { return (Basemenu *) sendToMenu; }

  void reconfigure(void);
  void setClosable(void);

  virtual void show(void);
};


#endif // __Windowmenu_hh
