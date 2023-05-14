// CEditableListCtrl.cpp : implementation file
//
#pragma once


#include "pch.h"
#include "CEditableListCtrl.h"
#include "Resource.h"

// CEditableListCtrl

IMPLEMENT_DYNAMIC(CEditableListCtrl, CListCtrl)

BEGIN_MESSAGE_MAP(CEditableListCtrl, CListCtrl)
END_MESSAGE_MAP()



// CEditableListCtrl message handlers

int CEditableListCtrl::GetRowFromPoint( CPoint &point, int *col ) const
{
    int column = 0; 
    int row = HitTest( point, NULL );   
     
    if( col ) *col = 0;     
     
    // Make sure that the ListView is in LVS_REPORT 
    if( ( GetWindowLong( m_hWnd, GWL_STYLE ) & LVS_TYPEMASK ) != LVS_REPORT )
    {
        return row;
    }
     
    // Get the top and bottom row visible   
    row = GetTopIndex();    
    int bottom = row + GetCountPerPage();
 
    if( bottom > GetItemCount() )
    {       
        bottom = GetItemCount();        
    }
     
    // Get the number of columns    
    CHeaderCtrl* pHeader = (CHeaderCtrl*)GetDlgItem( 0 );   
    int nColumnCount = pHeader->GetItemCount();
     
    // Loop through the visible rows    
    for( ; row <= bottom; row++ )    
    {       
        // Get bounding rectangle of item and check whether point falls in it.
        CRect rect;     
        GetItemRect( row, &rect, LVIR_BOUNDS );     
         
        if( rect.PtInRect(point) )      
        {           
            // Find the column      
            for( column = 0; column < nColumnCount; column++ )           
            {               
                int colwidth = GetColumnWidth( column );    
 
                if( point.x >= rect.left && point.x <= (rect.left + colwidth ) )
                {                   
                    if( col ) *col = column;                    
                    return row;             
                }               
                 
                rect.left += colwidth;
            }       
        }   
    }   
     
    return -1;
}


void CEditableListCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
    int index;
    CListCtrl::OnLButtonDown(nFlags, point);

    ModifyStyle(0, LVS_EDITLABELS);

    int colnum;

    if ((index = GetRowFromPoint(point, &colnum)) != -1)
    {
        UINT flag = LVIS_FOCUSED;

        if ((GetItemState(index, flag) & flag) == flag && (colnum == 1 || colnum == 2 || colnum == 3))
        {
            //
        }
        else
        {
            SetItemState(index, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
        }
    }
}

