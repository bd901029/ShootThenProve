//
//  Reachability.swift
//  ShootThenProve
//
//  Created by developer on 2019/6/7.
//  Copyright © 2019 Erynnis. All rights reserved.
//

import UIKit

class Reachability {
	class func isConnectedToNetwork() -> Bool{
		let url = URL(string: "https://www.google.com/")!
		do {
			let data = try Data(contentsOf: url)
			return data != nil
		} catch let error {
			print(error)
		}
		
		return false
	}
}
