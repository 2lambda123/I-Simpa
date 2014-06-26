function f = BuildBoundaryStructure(ft,mat)
%BuildBoundaryStructure G�n�re une structure de donn�es de Limites en
%fonction des mat�riaux pass�s en param�tre et de la matrice de translation
clear bnd;
bnd=mat.materials;
%Cr�ation de bnd.ind
bnd.ind=ones(1,size(ft,1));
%Affectation des mat�riaux de la sc�ne
for idsolid=1:size(mat.faces,2)
    id=1;
    for i=mat.faces{idsolid}
       bnd.ind(find(ft(:,i)==1))=mat.assoc{idsolid}(id);
       id=id+1;
    end
end
f=bnd;