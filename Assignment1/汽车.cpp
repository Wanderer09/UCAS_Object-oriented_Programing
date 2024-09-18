using namespace std; 

//厂家 
class CarFromManufacturer {
private:
    string model;          // 型号 
    string manufacturer;   // 制造商 
    string productionDate; // 生产日期 
    int warrantyYears;          // 保修期

public:
    CarFromManufacturer(string m, string mf, string pd, int wy) 
        : model(m), manufacturer(mf), productionDate(pd), warrantyYears(wy) {}

    string getModel() const { return model; }
    string getManufacturer() const { return manufacturer; }
    string getProductionDate() const { return productionDate; }

    bool isUnderWarranty() const {
        return warrantyYears > 0;
    }

    void repair() {
        cout << "Repairing on car: " << model << endl;
    }
};

//车主
 class CarFromOwner {
 private:
     string licensePlate;  // 车牌号
     double miles;            // 行驶里程
     string fuelType;      // 汽油类型
     bool isInsured;            // 是否有保险 
 
 public:
     CarFromOwner(string lp, double m, string ft, bool insured)
         : licensePlate(lp), mileage(m), fuelType(ft), isInsured(insured) {}
 
     string getLicensePlate() const { return licensePlate; }
     double getMiles() const { return miles; }
 
     void drive(double distance) {
         mileage += distance;
         cout << "Car driven for " << distance << " km. Total mileage: " << mileage << " km." << endl;
     }
 
     bool checkInsurance() const { return isInsured; }
 
     void renewInsurance() { isInsured = true; }
 };
 
 //交通管理机构
  class CarFromTrafficAuthority {
  private:
      string registrationNumber;  // 登记号
      string ownerName;           // 车主姓名
      string registrationDate;    // 登记日期
      bool passedInspection;           // 年检
  
  public:
      CarFromTrafficAuthority(string rn, string on, string rd, bool pi) 
          : registrationNumber(rn), ownerName(on), registrationDate(rd), passedInspection(pi) {}
  
      string getRegistrationNumber() const { return registrationNumber; }
      string getOwnerName() const { return ownerName; }
  
      bool isInspectionPassed() const { return passedInspection; }
  
      void updateInspectionStatus(bool status) {
          passedInspection = status;
          cout << "Inspection status updated: " << (status ? "Passed" : "Not Passed") << endl;
      }
  };
  
