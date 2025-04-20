class Node:
    def __init__(self, key, exp):
        self.key = key
        self.exp = exp
        self.prev = None
        self.next = None
    
class AuthenticationManager:

    '''
    create Dobuly linked list
    unexpired tokens are on right  
    expired will be on left , which is removed before any actions can happen
    
    on each operation 
    remove element from left of the node which has exp time exceeds current time
    
    on add :
    add node to hash map and add node to end of DLL 
    
    (inf,inf) -> node -> (inf,inf)
    
    on renew :
    check if node in DLL , then remove from first place add it to last because its renewed now
    before renwewal : (inf,inf) -> first -> node-a -> node-b -> (inf,inf)
    after renwewal  : (inf,inf) -> node-a -> node-b -> first -> (inf,inf)
    
    
    on count :
    return length of hashmap because it can only have unexpired tokens 
    '''
    
    
    def __init__(self, timeToLive: int):
        self.ttl = timeToLive
        self.head = Node(float('inf'),float('inf'))
        self.tail = Node(float('inf'),float('inf'))
        
        self.head.next = self.tail
        self.tail.prev = self.head
        
        self.lookup = {}

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.cleanup(currentTime)
        
        self.lookup[tokenId] = Node(tokenId, currentTime + self.ttl)
        self.addNode(self.lookup[tokenId])

    def renew(self, tokenId: str, currentTime: int) -> None:
        self.cleanup(currentTime)
        
        if tokenId in self.lookup:
            self.deleteNode(tokenId)
            del self.lookup[tokenId] 
            
            self.lookup[tokenId] = Node(tokenId, currentTime + self.ttl)
            self.addNode(self.lookup[tokenId])

    def countUnexpiredTokens(self, currentTime: int) -> int:
        self.cleanup(currentTime)
        
        return len(self.lookup)
    
    def cleanup(self, currentTime):
        
        head = self.head.next
        
        while head and head.key != float('inf') and head.exp <= currentTime:
            
            node = head
            head = head.next
            
            self.deleteNode(node.key)
            del self.lookup[node.key]
                
    def addNode(self,node):
        
        prev = self.tail.prev
        
        prev.next = node
        node.next = self.tail
        
        self.tail.prev = node
        node.prev = prev
    
    def deleteNode(self,key):
        
        node = self.lookup[key]
        
        next = node.next
        prev = node.prev
        
        prev.next = next
        next.prev = prev
        
# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)