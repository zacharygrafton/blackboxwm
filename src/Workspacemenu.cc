// Workspacemenu.cc for Blackbox - an X11 Window manager
// Copyright (c) 2001 Sean 'Shaleh' Perry <shaleh@debian.org>
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

// stupid macros needed to access some functions in version 2 of the GNU C
// library
#ifndef   _GNU_SOURCE
#define   _GNU_SOURCE
#endif // _GNU_SOURCE

#ifdef    HAVE_CONFIG_H
#  include "../config.h"
#endif // HAVE_CONFIG_H

#include "i18n.hh"
#include "blackbox.hh"
#include "Screen.hh"
#include "Toolbar.hh"
#include "Workspacemenu.hh"
#include "Workspace.hh"


Workspacemenu::Workspacemenu(BScreen *scrn)
    : Basemenu( scrn->screen() )
{
  screen = scrn;

  setTitle(i18n->getMessage(WorkspacemenuSet, WorkspacemenuWorkspacesTitle,
                            "Workspaces"));
  showTitle();

  insert( i18n->getMessage( WorkspacemenuSet,
                            WorkspacemenuNewWorkspace, "New Workspace" ) );
  insert( i18n->getMessage( WorkspacemenuSet,
                            WorkspacemenuRemoveLast, "Remove Last" ) );
  insertSeparator();
}


void Workspacemenu::itemClicked( const Point &, const Item &item, int button )
{
  if ( button != 1 )
    return;

  if ( item.index() == 0 )
    screen->addWorkspace();
  else if ( item.index() == 1 )
    screen->removeLastWorkspace();
  else if ( ( screen->getCurrentWorkspace()->getWorkspaceID() !=
              ( item.index() - 3)) && ( ( item.index() - 3) < screen->getCount() ) ) {
    screen->changeWorkspaceID( item.index() - 3 );
    hideAll();
  }
}
