#ifndef _ITEMCONTAINER_H_
#define _ITEMCONTAINER_H_

#include <map>

#include <Common.h>

#include "Forwards.h"

namespace Core
{

   using ItemMap = std::map< uint8_t, ItemPtr >;

   class ItemContainer 
   {

   public:
      ItemContainer( uint16_t storageId, uint8_t maxSize, const std::string& tableName, bool isMultiStorage );
      ~ItemContainer();

      uint16_t getId() const;

      uint8_t getEntryCount() const;

      void removeItem( uint8_t slotId );

      ItemMap& getItemMap();

      const ItemMap& getItemMap() const;

      ItemPtr getItem( uint8_t slotId );

      void setItem( uint8_t slotId, ItemPtr item );

      int8_t getFreeSlot();

      uint8_t getMaxSize() const;

      std::string getTableName() const;

      bool isMultiStorage() const;
      
   private:
      uint16_t m_id;
      uint8_t m_size;
      std::string m_tableName;
      bool m_bMultiStorage;
      ItemMap m_itemMap;
      Entity::PlayerPtr m_pOwner;
   };

}

#endif
