/* ----------------------------------------------------------------------
* I-SIMPA (http://i-simpa.ifsttar.fr). This file is part of I-SIMPA.
*
* I-SIMPA is a GUI for 3D numerical sound propagation modelling dedicated
* to scientific acoustic simulations.
* Copyright (C) 2007-2014 - IFSTTAR - Judicael Picaut, Nicolas Fortin
*
* I-SIMPA is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
* 
* I-SIMPA is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA or 
* see <http://ww.gnu.org/licenses/>
*
* For more information, please consult: <http://i-simpa.ifsttar.fr> or 
* send an email to i-simpa@ifsttar.fr
*
* To contact Ifsttar, write to Ifsttar, 14-20 Boulevard Newton
* Cite Descartes, Champs sur Marne F-77447 Marne la Vallee Cedex 2 FRANCE
* or write to scientific.computing@ifsttar.fr
* ----------------------------------------------------------------------*/

#include "e_scene_volumes.h"
#include "e_scene_volumes_volume.h"
#include "last_cpp_include.hpp"

E_Scene_Volumes::E_Scene_Volumes( wxXmlNode* noeudCourant ,  Element* parent)
:Element(parent,"Volumes",Element::ELEMENT_TYPE_SCENE_VOLUMES,noeudCourant)
{
	
	SetIcon(GRAPH_STATE_EXPANDED,GRAPH_VOLUMES_OPEN);
	SetIcon(GRAPH_STATE_NORMAL,GRAPH_VOLUMES_CLOSE);
	if(noeudCourant!=NULL)
	{
		wxXmlNode* currentChild;
		currentChild = noeudCourant->GetChildren();
		// On va créer les fils de notre noeudCourant
		wxString propValue;
		while(currentChild!=NULL)
		{
			if(currentChild->GetPropVal("eid",&propValue))
			{
				long typeEle;
				propValue.ToLong(&typeEle);
				
				if(typeEle==Element::ELEMENT_TYPE_SCENE_VOLUMES_VOLUME )
				{
					this->AppendFils(new E_Scene_Volumes_Volume(currentChild,this));
				}
			}
			currentChild = currentChild->GetNext();
		}
	}
}

E_Scene_Volumes::E_Scene_Volumes( Element* parent)
:Element(parent,"Volumes",Element::ELEMENT_TYPE_SCENE_VOLUMES)
{
	SetIcon(GRAPH_STATE_EXPANDED,GRAPH_VOLUMES_OPEN);
	SetIcon(GRAPH_STATE_NORMAL,GRAPH_VOLUMES_CLOSE);
	_("Volumes");
}


Element* E_Scene_Volumes::AppendFilsByType(ELEMENT_TYPE etypefils,const wxString& libelle)
{
	if(etypefils==Element::ELEMENT_TYPE_SCENE_VOLUMES_VOLUME )
	{
		return this->AppendFils(new E_Scene_Volumes_Volume(this));
	}
	return Element::AppendFilsByType(etypefils,libelle);
}

wxXmlNode* E_Scene_Volumes::SaveXMLCoreDoc(wxXmlNode* NoeudParent)
{
	wxXmlNode* thisNode = new wxXmlNode(NoeudParent,wxXML_ELEMENT_NODE,"subdomains");
	Element::SaveXMLCoreDoc(thisNode);
	return thisNode;
}

wxXmlNode* E_Scene_Volumes::SaveXMLDoc(wxXmlNode* NoeudParent)
{
	wxXmlNode* thisNode = Element::SaveXMLDoc(NoeudParent);
	thisNode->SetName("volumes"); // Nom de la balise xml ( pas d'espace autorise )

	return thisNode;
}
void E_Scene_Volumes::OnRightClic(wxMenu* leMenu)
{
	leMenu->Append(GetMenuItem(leMenu,IDEVENT_NEW_VOLUME, _("Create a volume"),"./Bitmaps/popup_new.png"));
	leMenu->Append(GetMenuItem(leMenu,IDEVENT_BUILD_VOLUMES_FROM_TRIMESH, _("Volume auto-detect"),"./Bitmaps/popup_new.png"));
	Element::OnRightClic(leMenu);
}
