#include "data_manager\base_core_configuration.h"
/**
 * @file core_configuration.h
 * @brief Gestion des donn�es de configuration
 *
 * Cette classe permet d'acceder aux informations de la sc�ne de facon optimis� et simple
 */

#ifndef __CORE_CONFIGURATION__
#define __CORE_CONFIGURATION__

/**
 * @brief Gestion des donn�es de configuration
 *
 * Cette classe permet d'acceder aux informations de la sc�ne de facon optimis� et simple
 */
class Core_Configuration : public Base_Core_Configuration
{
public:
	/**
	 * Enumeration des propri�t�s de type chaine
	 */
	enum SPROP
	{
		SPROP_DIRECT_RECEPTEUR_S_FILE_PATH,
		SPROP_SABINE_RECEPTEUR_S_FILE_PATH,
		SPROP_EYRING_RECEPTEUR_S_FILE_PATH,
		SPROP_OTHER_CORE_OUTPUT_PATH
	};
	/**
	 * Enumeration des propri�t�s de type float
	 */
	enum FPROP
	{
		FPROP_NONE							/*!<  */
	};
	/**
	 * Enumeration des propri�t�s de type entier
	 */
	enum IPROP
	{
		IPROP_DO_CALC_ABS_ATMO,						/*!< Calcul de l'absorption atmosph�rique */
		IPROP_CALC_TO_EXT_CORE,						/*!< Calcul � destination d'un autre code de calcul et non pour l'utilisateur */
		IPROP_OUTPUT_RECEPTEURS_SURF_BY_FREQ,	/*!< Sortie des r�cepteurs de surface par bande de fr�quence */
		IPROP_DO_SURFACE_ANGULAR_WEIGHTING    /*!< Pond�ration de l'�nergie selon l'angle d'incidence sur les r�cepteurs de surfaces*/
	};
	/**
	 * Initialisation des param�tres du coeur de calcul � partir d'un fichier XML
	 * @param xmlFilePath Chemin du fichier XML
	 */
	Core_Configuration( CoreString xmlFilePath );
	/**
	 * Destructeur
	 */
	~Core_Configuration( );
	/////////////////////////////////////////////////////////
	//	Tr�s rapide
	/////////////////////////////////////////////////////////
	inline decimal* FastGetConfigValue(FPROP propertyIndex){return (tabFloatProp+propertyIndex); }
	inline CoreString* FastGetConfigValue(SPROP propertyIndex){return (tabStringProp+propertyIndex); }
	inline entier* FastGetConfigValue(IPROP propertyIndex){return (tabIntProp+propertyIndex); }

	inline decimal* FastGetConfigValue(BASE_FPROP propertyIndex){return (tabFloatProp+propertyIndex); }
	inline CoreString* FastGetConfigValue(BASE_SPROP propertyIndex){return (tabStringProp+propertyIndex); }
	inline entier* FastGetConfigValue(BASE_IPROP propertyIndex){return (tabIntProp+propertyIndex); }

	bool CalculationForOutsideCore(){ return *FastGetConfigValue(IPROP_CALC_TO_EXT_CORE); }
private:

	void SetConfigInformation(FPROP propertyIndex,decimal valeur);
	void SetConfigInformation(SPROP propertyIndex,CoreString valeur);
	void SetConfigInformation(IPROP propertyIndex,entier valeur);
	void SetConfigInformation(BASE_FPROP propertyIndex,decimal valeur);
	void SetConfigInformation(BASE_SPROP propertyIndex,CoreString valeur);
	void SetConfigInformation(BASE_IPROP propertyIndex,entier valeur);


};

#endif
