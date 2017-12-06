

 % Source d'energie acoustique, second membre e.d.p.
Srce_sonore=load(strcat(domaine,'_sources.txt'));

xs=Srce_sonore(1,1) ;ys=Srce_sonore(1,2) ;zs=Srce_sonore(1,3) ;% Position de la source

dist2S=(xdf-xs).^2+(ydf-ys).^2+(zdf-zs).^2; % Distance de tous les degr�s de libert� � la source
rayonS2=0.15^2;% Carr� du Rayon de la source volumique de puissance 
VolSource=-10;
while VolSource<=0
ind=1:NDOF;rayonS2=rayonS2*1.25;% Incr�mentation du rayon
ind=ind(dist2S<rayonS2);% contient les indice des ddl dans la sph�re 
VolSource=sum(V_VC(ind));% Volume effectif occup� par la source= somme de tous les volumes d�finis autour des points  " ind "
end   
VolSource% Volume occup� par la source dans le maillage
Srce_sonore(1,4:end)=1e-12*10.^(Srce_sonore(1,4:end)/10); % Puissance de toutes les octaves 

