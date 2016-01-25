#----------------------------------------------------------------------
# I-SIMPA (http://i-simpa.ifsttar.fr). This file is part of I-SIMPA.
#
# I-SIMPA is a GUI for 3D numerical sound propagation modelling dedicated
# to scientific acoustic simulations.
# Copyright (C) 2007-2014 - IFSTTAR - Judicael Picaut, Nicolas Fortin
#
# I-SIMPA is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
# 
# I-SIMPA is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA or 
# see <http://ww.gnu.org/licenses/>
#
# For more information, please consult: <http://i-simpa.ifsttar.fr> or 
# send an email to i-simpa@ifsttar.fr
#
# To contact Ifsttar, write to Ifsttar, 14-20 Boulevard Newton
# Cite Descartes, Champs sur Marne F-77447 Marne la Vallee Cedex 2 FRANCE
# or write to scientific.computing@ifsttar.fr
# ----------------------------------------------------------------------

# -*- coding: cp1252 -*-
#####################
# Ce script cr�� un fichier de particules qui forme une sinuso�de
#
#####################




import libsimpa as ls
from math import *

pwriter=ls.ParticuleIO()
pwriter.OpenForWrite("particules.pbin")
pwriter.SetHeaderData(.02)
nbpart=10000
nbtimestep=12
pospart=[[i/800.,2,1+pi/100.*(i/10.)] for i in range(0,nbpart)]

for part in pospart:
    pwriter.NewParticle(0) #pas de temps de d�part n�0
    for i in range(0,nbtimestep):
        pwriter.NewPositionParticle(part[0],2,(sin(part[2]+(i*(pi/6)))+2),1.)
pwriter.Close()
