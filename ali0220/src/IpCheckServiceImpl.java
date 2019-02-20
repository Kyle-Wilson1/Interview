import java.util.HashMap;
import java.util.Map;

public class IpCheckServiceImpl implements IpCheckService {

    private long[] bitMap = new long[134217728];

    private Map<Long, Boolean> ipAddressMap = new HashMap<>();

    @Override
    public boolean isInList(String ipAddress) {

        long ip = ipString2Long(ipAddress);
        // hashmap
//        Boolean ret = ipAddressMap.get(ip);
//        return ret != null;

        // bitmap
        int location = (int) (ip / 32);
        long pos = ip % 32;

        if ((bitMap[location] & (1 << pos)) > 0) {
            return true;
        }
        return false;
    }

    // ip地址转为32位的数字
    public long ipString2Long(String ipAddress) {

        long result = 0;
        String[] ipAddressInArray = ipAddress.split("\\.");

        for (int i = 0; i <= 3; ++i) {
            long ip = Long.parseLong(ipAddressInArray[i]);
            result |= ip << ((3 - i) * 8);
        }

        return result;
    }

    // 插入ip名单
    public void insert(String ipAddress) {
        // hashmap
        long ip = ipString2Long(ipAddress);
        ipAddressMap.put(ip, true);

        // bitmap
        int location = (int) (ip / 32);
        long pos = ip % 32;

        bitMap[location] |= (1 << pos);
    }

}
